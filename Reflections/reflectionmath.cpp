#include "reflectionmath.h"
#include <vector>
#include <math.h>
#include <complex>
//#include <numbers>

namespace ReflectionMath
{
template<typename type> type intercept(type &vp1, type &dn1, type &vp2, type &dn2)
{
    return 0.5f*((dn2-dn1)/2.0f/(dn2+dn1)+(vp2-vp1)/2.0f/(vp2+vp1));
}
template float intercept<float>(float &vp1, float &dn1, float &vp2, float &dn2);

template<typename type> type gradient(type &vp1, type &vs1, type &dn1, type &vp2, type &vs2, type &dn2)
{
    type vp_mean = (vp1+vp2)/2;
    type vs_mean = (vs1+vs2)/2;
    type dn_mean = (dn1+dn2)/2;
    type vp_diff = vp2-vp1;
    type vs_diff = vs2-vs1;
    type dn_diff = dn2-dn1;
    type vsvp2 = vs_mean/vp_mean;
    vsvp2 *= vsvp2;
    return 0.5f*vp_diff/vp_mean-4.0f*vsvp2*vs_diff/vs_mean-2.0f*vsvp2*dn_diff/dn_mean;
}
template float gradient<float>(float &vp1, float &vs1, float &dn1, float &vp2, float &vs2, float &dn2);

template<typename type> type intercept_short(type &vp_diff, type &vp_mean, type &dn_diff, type &dn_mean)
{
    return 0.5f*(dn_diff/dn_mean+vp_diff/vp_mean);
}
template float intercept_short<float>(float &vp_diff, float &vp_mean, float &dn_diff, float &dn_mean);

template<typename type> type gradient_short(type &vp_diff, type &vp_mean, type &vs_diff, type &vs_mean, type &dn_diff, type &dn_mean)
{
    type vsvp2 = vs_mean/vp_mean;
    vsvp2 *= vsvp2;
    return 0.5f*vp_diff/vp_mean-4.0f*vsvp2*(0.5f*dn_diff/dn_mean+vs_diff/vs_mean);
}
template float gradient_short(float &vp_diff, float &vp_mean, float &vs_diff, float &vs_mean, float &dn_diff, float &dn_mean);

template<typename type> void compute_diff_and_mean_values(type &vp1, type &vs1, type &dn1, type &vp2, type &vs2, type &dn2, type &angle,
                                                          std::complex<type> &angle_rad, std::complex<type> &angle_rad_2, std::complex<type> &angle_rad_mean,
                                                          type &vp_diff, type &vs_diff, type &dn_diff,
                                                          type &vp_mean, type &vs_mean, type &dn_mean)
{
    angle_rad = std::complex<type>(angle/180.0f*3.1415926535f,0);
    angle_rad_2 = std::asin(std::sin(angle_rad)/vp1*vp2);
    angle_rad_mean = (angle_rad_2+angle_rad)/2.0f;
    vp_mean = (vp1+vp2)/2.0f;
    vs_mean = (vs1+vs2)/2.0f;
    dn_mean = (dn1+dn2)/2.0f;
    vp_diff = vp2-vp1;
    vs_diff = vs2-vs1;
    dn_diff = dn2-dn1;
}

std::complex<float> aki_rpp_lecture(float &vp1, float &vs1, float &dn1, float &vp2, float &vs2, float &dn2, float &angle)
{
    std::complex<float> angle_rad, angle_rad_2, angle_rad_mean;
    float vp_diff, vs_diff, dn_diff, vp_mean, vs_mean, dn_mean;
    compute_diff_and_mean_values<float>(vp1,vs1,dn1,vp2,vs2,dn2,angle,angle_rad,angle_rad_2, angle_rad_mean, vp_diff, vs_diff, dn_diff, vp_mean, vs_mean, dn_mean);
    std::complex<float> common_part_1 = vs_mean/vp_mean*std::sin(angle_rad_mean);
    std::complex<float> common_part_3 = std::tan(angle_rad_mean);
    common_part_1 *= common_part_1;
    return 0.5f*(1.0f-4.0f*common_part_1)*dn_diff/dn_mean+0.5f*(1.0f+common_part_3*common_part_3)*vp_diff/vp_mean-4.0f*common_part_1*vs_diff/vs_mean;
}

std::complex<float> shuye_rpp_lecture(float &vp1, float &vs1, float &dn1, float &vp2, float &vs2, float &dn2, float &angle)
{
    std::complex<float> angle_rad, angle_rad_2, angle_rad_mean;
    float vp_diff, vs_diff, dn_diff, vp_mean, vs_mean, dn_mean;
    compute_diff_and_mean_values<float>(vp1,vs1,dn1,vp2,vs2,dn2,angle,angle_rad,angle_rad_2, angle_rad_mean, vp_diff, vs_diff, dn_diff, vp_mean, vs_mean, dn_mean);
    std::complex<float> vp_diff_vp_mean = vp_diff/vp_mean;
    std::complex<float> dn_diff_dn_mean = dn_diff/dn_mean;
    std::complex<float> vs_mean_vp_mean = vs_mean/vp_mean;
    std::complex<float> sin2 = std::sin(angle_rad_mean);
    sin2*=sin2;
    return 0.5f*(dn_diff_dn_mean+vp_diff_vp_mean)+(0.5f*vp_diff_vp_mean-4.0f*vs_mean_vp_mean*vs_mean_vp_mean*(0.5f*dn_diff_dn_mean+vs_diff/vs_mean))*sin2+0.5f*vp_diff_vp_mean*sin2*sin2/(1.0f-sin2);
}

template<typename type> void zoeppritz_angles(type v11, type v21, type v12, type v22,
                                              type &angle_11, std::complex<type> &p, std::complex<type> &p2,
                                              std::complex<type> &angle_11_sin, std::complex<type> &angle_12_sin, std::complex<type> &angle_21_sin, std::complex<type> &angle_22_sin,
                                              std::complex<type> &angle_11_cos, std::complex<type> &angle_12_cos, std::complex<type> &angle_21_cos, std::complex<type> &angle_22_cos,
                                              std::complex<type> &angle_11_cos_v11, std::complex<type> &angle_12_cos_v12, std::complex<type> &angle_21_cos_v21, std::complex<type> &angle_22_cos_v22)
{
    // method is used for angles computation
    // the first index means the wave type (p or s). If input angle11 is p, 1 means p, 2 means s. If input angle11 is s, 1 means s, 2 means p.
    // the second index means the layer. The wave is always falling from the side of layer 1.
    // the reason this method is not using p and s signs directy is that the input angle11 can be any of p or s waves (theoretically for the waves coming from layer 2 to layer 1 as well)
    angle_11_sin = std::sin(std::complex<type>(angle_11/180.f*3.1415926535f,0));
    p = angle_11_sin/v11;
    angle_12_sin = p * v12;
    angle_21_sin = p * v21;
    angle_22_sin = p * v22;
    angle_11_cos = std::sqrt(1.0f-angle_11_sin*angle_11_sin);
    angle_12_cos = std::sqrt(1.0f-angle_12_sin*angle_12_sin);
    angle_21_cos = std::sqrt(1.0f-angle_21_sin*angle_21_sin);
    angle_22_cos = std::sqrt(1.0f-angle_22_sin*angle_22_sin);
    angle_11_cos_v11 = angle_11_cos/v11;
    angle_12_cos_v12 = angle_12_cos/v12;
    angle_21_cos_v21 = angle_21_cos/v21;
    angle_22_cos_v22 = angle_22_cos/v22;
    p2 = p * p;
}
//template void zoeppritz_angles<float>(float v11, float v21, float v12, float v22,
//                                      float &angle_11, std::complex<float> &p, std::complex<float> &p2,
//                                      std::complex<float> &angle_11_sin, std::complex<float> &angle_12_sin, std::complex<float> &angle_21_sin, std::complex<float> &angle_22_sin,
//                                      std::complex<float> &angle_11_cos, std::complex<float> &angle_12_cos, std::complex<float> &angle_21_cos, std::complex<float> &angle_22_cos,
//                                      std::complex<float> &angle_11_cos_v11, std::complex<float> &angle_12_cos_v12, std::complex<float> &angle_21_cos_v21, std::complex<float> &angle_22_cos_v22);

template<typename type> std::complex<type> zoeppritz_rpp(type &vp1, type &vs1, type &dn1, type &vp2, type &vs2, type &dn2, type &angle)
{
    std::complex<type> angle_p1_sin = std::sin(std::complex<type>(angle/180.f*3.1415926535f,0));
    std::complex<type> p = angle_p1_sin/vp1;
    std::complex<type> angle_p2_sin = p * vp2;
    std::complex<type> angle_s1_sin = p * vs1;
    std::complex<type> angle_s2_sin = p * vs2;
    std::complex<type> angle_p1_cos = std::sqrt(1.0f-angle_p1_sin*angle_p1_sin);
    std::complex<type> angle_p2_cos = std::sqrt(1.0f-angle_p2_sin*angle_p2_sin);
    std::complex<type> angle_s1_cos = std::sqrt(1.0f-angle_s1_sin*angle_s1_sin);
    std::complex<type> angle_s2_cos = std::sqrt(1.0f-angle_s2_sin*angle_s2_sin);
    std::complex<type> p2 = p*p;
    type vs22 = vs2 * vs2;
    type vs12 = vs1 * vs1;
    std::complex<type> angle_p1_cos_vp1 = angle_p1_cos/vp1;
    std::complex<type> angle_p2_cos_vp2 = angle_p2_cos/vp2;
    std::complex<type> angle_s1_cos_vs1 = angle_s1_cos/vs1;
    std::complex<type> angle_s2_cos_vs2 = angle_s2_cos/vs2;
    zoeppritz_angles<float>(vp1, vs1, vp2, vs2, angle, p, p2,
                            angle_p1_sin, angle_p2_sin, angle_s1_sin, angle_s2_sin,
                            angle_p1_cos, angle_p2_cos, angle_s1_cos, angle_s2_cos,
                            angle_p1_cos_vp1, angle_p2_cos_vp2, angle_s1_cos_vs1, angle_s2_cos_vs2);
    std::complex<type> a = dn2 * (1.0f - 2.0f * vs22 * p2) - dn1 * (1.0f - 2.0f * vs12 * p2);
    std::complex<type> b = dn2 * (1.0f - 2.0f * vs22 * p2) + 2 * dn1 * vs12 * p2;
    std::complex<type> c = dn1 * (1.0f - 2.0f * vs12 * p2) + 2 * dn2 * vs22 * p2;
    std::complex<type> d = 2 * (dn2 * vs22 - dn1 * vs12);
    std::complex<type> e = b * angle_p1_cos_vp1 + c * angle_p2_cos_vp2;
    std::complex<type> f = b * angle_s1_cos_vs1 + c * angle_s2_cos_vs2;
    std::complex<type> g = a - d * angle_p1_cos_vp1 * angle_s2_cos_vs2;
    std::complex<type> h = a - d * angle_p2_cos_vp2 * angle_s1_cos_vs1;
    std::complex<type> dd = e * f + g * h * p2;
    return ((b * angle_p1_cos_vp1 - c * angle_p2_cos_vp2) * f - (a + d * angle_p1_cos_vp1 * angle_s2_cos_vs2) * h * p2)/dd;
}
template std::complex<float> zoeppritz_rpp<float>(float &vp1, float &vs1, float &dn1, float &vp2, float &vs2, float &dn2, float &angle);

template<typename type> std::complex<type> zoeppritz_rps(type &vp1, type &vs1, type &dn1, type &vp2, type &vs2, type &dn2, type &angle)
{
    return 0.0f;
}

}

