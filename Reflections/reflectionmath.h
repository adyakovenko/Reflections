#ifndef REFLECTIONMATH_H
#define REFLECTIONMATH_H
#include <vector>
#include <math.h>
#include <complex>

namespace ReflectionMath
{
template<typename type> type intercept(type &vp1, type &dn1, type &vp2, type &dn2);
template<typename type> type gradient(type &vp1, type &vs1, type &dn1, type &vp2, type &vs2, type &dn2);

std::complex<float> aki_rpp_lecture(float &vp1, float &vs1, float &dn1, float &vp2, float &vs2, float &dn2, float &angle);
std::complex<float> shuye_rpp_lecture(float &vp1, float &vs1, float &dn1, float &vp2, float &vs2, float &dn2, float &angle);

template<typename type> std::complex<type> zoeppritz_rpp(type &vp1, type &vs1, type &dn1, type &vp2, type &vs2, type &dn2, type &angle);

};

#endif // REFLECTIONMATH_H
