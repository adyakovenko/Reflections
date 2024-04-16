#include "windowmain.h"
#include "ui_windowmain.h"
#include "reflectionmath.h"
#include <complex>

using namespace ReflectionMath;

WindowMain::WindowMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowMain)
{
    ui->setupUi(this);

    // set all manual connections
    connect(ui->spinBox_vp1,SIGNAL(valueChanged(int)),this,SLOT(on_layer_parameter_changed()));
    connect(ui->spinBox_vp2,SIGNAL(valueChanged(int)),this,SLOT(on_layer_parameter_changed()));
    connect(ui->spinBox_vs1,SIGNAL(valueChanged(int)),this,SLOT(on_layer_parameter_changed()));
    connect(ui->spinBox_vs2,SIGNAL(valueChanged(int)),this,SLOT(on_layer_parameter_changed()));
    connect(ui->doubleSpinBox_dn1,SIGNAL(valueChanged(double)),this,SLOT(on_layer_parameter_changed()));
    connect(ui->doubleSpinBox_dn2,SIGNAL(valueChanged(double)),this,SLOT(on_layer_parameter_changed()));
    connect(ui->spinBox_angle_min,SIGNAL(valueChanged(int)),this,SLOT(on_plot_range_angles_changed()));
    connect(ui->spinBox_angle_max,SIGNAL(valueChanged(int)),this,SLOT(on_plot_range_angles_changed()));
    connect(ui->doubleSpinBox_r_min,SIGNAL(valueChanged(double)),this,SLOT(on_plot_range_r_changed()));
    connect(ui->doubleSpinBox_r_max,SIGNAL(valueChanged(double)),this,SLOT(on_plot_range_r_changed()));


    // run starting plot
    set_starting_parameters();

}

WindowMain::~WindowMain()
{
    delete ui;
}

void WindowMain::set_starting_parameters()
{
    // make unprepared widgets invisible
    bool flag = false;
    ui->label_wave_type->setVisible(flag);
    ui->comboBox_wave_type->setVisible(flag);

    // set drawing templates
    ui->plot_main->addGraph();
    ui->plot_main->addGraph();
    ui->plot_main->addGraph();
    ui->plot_main->graph(0)->setPen(QPen(Qt::red));
    ui->plot_main->graph(1)->setPen(QPen(Qt::blue));
    ui->plot_main->graph(2)->setPen(QPen(Qt::black));

    ui->plot_main->xAxis2->setVisible(true);
    ui->plot_main->yAxis2->setVisible(true);
    ui->plot_main->xAxis->setLabel("Angles");
    ui->plot_main->yAxis->setLabel("R");
    ui->plot_main->xAxis->setRange(0,90);
    ui->plot_main->yAxis->setRange(-1,1);
    ui->plot_main->xAxis2->setRange(0,90);
    ui->plot_main->yAxis2->setRange(-1,1);
    ui->checkBox_abs->setChecked(true);
    ui->checkBox_real->setChecked(true);
    ui->checkBox_imag->setChecked(true);
    ui->checkBox_angle->setChecked(true);
    ui->checkBox_r->setChecked(true);

    ui->comboBox_approx->clear();
    ui->comboBox_approx->addItem("Zoeppritz");
    ui->comboBox_approx->addItem("Aki-Richards");
    ui->comboBox_approx->addItem("Shuye");

    for(int a=0; a<angles.capacity();a++)
    {
        angles[a] = a;
        x[a] = a;
    }

    ui->checkBox_recalc->setChecked(true);
    on_pushButton_compute_clicked();
}

void WindowMain::set_main_plot()
{

    QFont fontt = font();
    fontt.setPointSize(20);
    ui->plot_main->setFont(fontt);
}

void WindowMain::on_pushButton_compute_clicked()
{
    // set approximation
    std::complex<float> (*approx)(float &vp1, float &vs1, float &dn1, float &vp2, float &vs2, float &dn2, float &angle);
    switch(ui->comboBox_approx->currentIndex())
    {
    case 0: approx = ReflectionMath::zoeppritz_rpp; break;
    case 1: approx = ReflectionMath::aki_rpp_lecture; break;
    case 2: approx = ReflectionMath::shuye_rpp_lecture; break;
    default: approx = ReflectionMath::zoeppritz_rpp; break;
    }
    float vp1 = ui->spinBox_vp1->value();
    float vp2 = ui->spinBox_vp2->value();
    float vs1 = ui->spinBox_vs1->value();
    float vs2 = ui->spinBox_vs2->value();
    float dn1 = ui->doubleSpinBox_dn1->value()*1000.0f;
    float dn2 = ui->doubleSpinBox_dn2->value()*1000.0f;
    std::vector<float> angles(90);


    for(int a=0;a<angles.capacity();a++)
    {
        angles[a] = a;
        std::complex<float> rpp = approx(vp1,vs1,dn1,vp2,vs2,dn2,angles[a]);
        rpp_real[a] = rpp.real();
        rpp_imag[a] = rpp.imag();
        rpp_abs[a] = std::sqrt(rpp.real()*rpp.real()+rpp.imag()*rpp.imag());
    }

    ui->plot_main->graph(0)->setData(x,rpp_real);
    ui->plot_main->graph(1)->setData(x,rpp_imag);
    ui->plot_main->graph(2)->setData(x,rpp_abs);

    ui->lineEdit_r->setText(QString::number(float(std::round(int(ReflectionMath::intercept<float>(vp1,dn1,vp2,dn2)*100.0f+0.5f))/100.0f)));
    ui->lineEdit_g->setText(QString::number(float(std::round(int(ReflectionMath::gradient<float>(vp1,vs1,dn1,vp2,vs2,dn2)*100.0f+0.5f))/100.0f)));
    if(ui->checkBox_r->isChecked())
    {
        reset_suggested_axis_r_values();
        set_axis_r(suggested_r_min, suggested_r_max);
    }
    if(ui->checkBox_angle->isChecked())
    {
        set_axis_angles(suggested_angle_min, suggested_angle_max);
    }
    ui->plot_main->replot();
}

void WindowMain::on_comboBox_approx_currentIndexChanged(int index)
{
    on_pushButton_compute_clicked();
}

void WindowMain::on_checkBox_angle_stateChanged(int arg1)
{
    bool enabled = !ui->checkBox_angle->isChecked();
    ui->spinBox_angle_min->setEnabled(enabled);
    ui->spinBox_angle_max->setEnabled(enabled);
    if(enabled)
        set_axis_angles(ui->spinBox_angle_min->value(),ui->spinBox_angle_max->value());

    else
        set_axis_angles(suggested_angle_min,suggested_angle_max);
    ui->plot_main->replot();
}

void WindowMain::on_checkBox_r_stateChanged(int arg1)
{
    bool enabled = !ui->checkBox_r->isChecked();
    ui->doubleSpinBox_r_min->setEnabled(enabled);
    ui->doubleSpinBox_r_max->setEnabled(enabled);
    if(enabled)
        set_axis_r(ui->doubleSpinBox_r_min->value(),ui->doubleSpinBox_r_max->value());
    else
    {
        reset_suggested_axis_r_values();
        set_axis_r(suggested_r_min, suggested_r_max);
    }
    if(ui->checkBox_recalc)
        ui->plot_main->replot();
}

void WindowMain::on_layer_parameter_changed()
{
    if(ui->checkBox_recalc->isChecked()) // check if plot sould be redrawn immediately
    {
        on_pushButton_compute_clicked();
    }
}

void WindowMain::on_plot_range_angles_changed()
{
    if(ui->checkBox_recalc->isChecked())
    {
        set_axis_angles(ui->spinBox_angle_min->value(),ui->spinBox_angle_max->value());
        ui->plot_main->replot();
    }
}

void WindowMain::on_plot_range_r_changed()
{
    if(ui->checkBox_recalc->isChecked())
    {
        set_axis_r(ui->doubleSpinBox_r_min->value(),ui->doubleSpinBox_r_max->value());
        ui->plot_main->replot();
    }
}

void WindowMain::on_checkBox_real_stateChanged(int arg1)
{
    ui->plot_main->graph(0)->setVisible(ui->checkBox_real->isChecked());
    ui->plot_main->replot();
}


void WindowMain::on_checkBox_imag_stateChanged(int arg1)
{
    ui->plot_main->graph(1)->setVisible(ui->checkBox_imag->isChecked());
    ui->plot_main->replot();
}


void WindowMain::on_checkBox_abs_stateChanged(int arg1)
{
    ui->plot_main->graph(2)->setVisible(ui->checkBox_abs->isChecked());
    ui->plot_main->replot();
}


void WindowMain::set_axis_angles(int minval, int maxval)
{
    ui->plot_main->xAxis->setRange(minval,maxval);
    ui->plot_main->xAxis2->setRange(minval,maxval);
}

template<typename type> void WindowMain::set_axis_r(type minval, type maxval)
{
    ui->plot_main->yAxis->setRange(minval,maxval);
    ui->plot_main->yAxis2->setRange(minval,maxval);
}

void WindowMain::reset_suggested_axis_r_values()
{
    double minval = std::numeric_limits<double>::max();
    double maxval = std::numeric_limits<double>::min();
    if(ui->checkBox_real->isChecked())
        suggested_single_range(rpp_real,minval,maxval);
    if(ui->checkBox_imag->isChecked())
        suggested_single_range(rpp_imag,minval,maxval);
    if(ui->checkBox_abs->isChecked())
        suggested_single_range(rpp_abs,minval,maxval);
    minval -= std::abs(minval/10.0f)-0.01;
    maxval += std::abs(maxval/10.0f)+0.01;
    suggested_r_min = std::max(minval,-3.0);
    suggested_r_max = std::min(maxval,3.0);
}

void WindowMain::suggested_single_range(QVector<double> &vector, double &suggested_min, double &suggested_max)
{
    double tmp_min = *std::min_element(vector.begin(),vector.end());
    double tmp_max = *std::max_element(vector.begin(),vector.end());
    if(tmp_min<suggested_min)
        suggested_min = tmp_min;
    if(tmp_max>suggested_max)
        suggested_max = tmp_max;
}

