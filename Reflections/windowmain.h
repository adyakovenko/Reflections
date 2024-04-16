#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <QMainWindow>
#include "reflectionmath.h"
#include <complex>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowMain; }
QT_END_NAMESPACE

class WindowMain : public QMainWindow
{
    Q_OBJECT

public:
    WindowMain(QWidget *parent = nullptr);
    ~WindowMain();

private:
    Ui::WindowMain *ui;

public:
    void set_main_plot();
    void set_starting_parameters();
private:
    void set_axis_angles(int minval, int maxval);
    template<typename type> void set_axis_r(type minval, type maxval);
    void reset_suggested_axis_r_values();
    void suggested_single_range(QVector<double> &vector, double &suggested_min, double &suggested_max);
private slots:
    void on_pushButton_compute_clicked();
    void on_checkBox_angle_stateChanged(int arg1);
    void on_checkBox_r_stateChanged(int arg1);
    void on_layer_parameter_changed();
    void on_plot_range_angles_changed();
    void on_plot_range_r_changed();

    void on_checkBox_real_stateChanged(int arg1);

    void on_checkBox_imag_stateChanged(int arg1);

    void on_checkBox_abs_stateChanged(int arg1);

    void on_comboBox_approx_currentIndexChanged(int index);

public:
    int suggested_angle_min = 0.0f;
    int suggested_angle_max = 85.0f;
    float suggested_r_min = -1.0f;
    float suggested_r_max = 1.0f;
    QVector<double>x = QVector<double>(90);
    QVector<double>rpp_real = QVector<double>(90);
    QVector<double>rpp_imag = QVector<double>(90);
    QVector<double>rpp_abs = QVector<double>(90);
    std::vector<float> angles = std::vector<float>(90);
};
#endif // WINDOWMAIN_H
