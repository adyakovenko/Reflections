/********************************************************************************
** Form generated from reading UI file 'windowmain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWMAIN_H
#define UI_WINDOWMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_WindowMain
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot_main;
    QComboBox *comboBox_wave_type;
    QLabel *label_wave_type;
    QGroupBox *groupBox_layers;
    QLabel *label_vp_4;
    QSpinBox *spinBox_vp1;
    QLabel *label_vp;
    QDoubleSpinBox *doubleSpinBox_dn2;
    QDoubleSpinBox *doubleSpinBox_dn1;
    QLabel *label_layer_2;
    QLabel *label_vs;
    QLabel *label_vp_2;
    QLabel *label_vp_3;
    QLabel *label_layer_1;
    QSpinBox *spinBox_vs2;
    QLabel *label_density;
    QSpinBox *spinBox_vp2;
    QSpinBox *spinBox_vs1;
    QGroupBox *groupBox_visual;
    QGroupBox *groupBox_parts;
    QCheckBox *checkBox_abs;
    QCheckBox *checkBox_imag;
    QCheckBox *checkBox_real;
    QGroupBox *groupBox_bound;
    QLabel *label_angles;
    QLabel *label_r;
    QLabel *label_bound_min;
    QSpinBox *spinBox_angle_max;
    QSpinBox *spinBox_angle_min;
    QDoubleSpinBox *doubleSpinBox_r_min;
    QLabel *label_bound_resize;
    QDoubleSpinBox *doubleSpinBox_r_max;
    QCheckBox *checkBox_angle;
    QCheckBox *checkBox_r;
    QLabel *label_bound_max;
    QLabel *label_approx;
    QComboBox *comboBox_approx;
    QGroupBox *groupBox_calc;
    QCheckBox *checkBox_recalc;
    QPushButton *pushButton_compute;
    QLabel *label_r0;
    QLineEdit *lineEdit_r;
    QLabel *label_g;
    QLineEdit *lineEdit_g;
    QGroupBox *groupBox_export;
    QPushButton *pushButton_graph;
    QPushButton *pushButton_window;
    QPushButton *pushButton_table;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowMain)
    {
        if (WindowMain->objectName().isEmpty())
            WindowMain->setObjectName(QString::fromUtf8("WindowMain"));
        WindowMain->resize(905, 540);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WindowMain->sizePolicy().hasHeightForWidth());
        WindowMain->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(WindowMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plot_main = new QCustomPlot(centralwidget);
        plot_main->setObjectName(QString::fromUtf8("plot_main"));
        plot_main->setGeometry(QRect(25, 25, 500, 465));
        sizePolicy.setHeightForWidth(plot_main->sizePolicy().hasHeightForWidth());
        plot_main->setSizePolicy(sizePolicy);
        plot_main->setMinimumSize(QSize(200, 200));
        plot_main->setSizeIncrement(QSize(1, 1));
        plot_main->setBaseSize(QSize(500, 500));
        QFont font;
        font.setPointSize(8);
        plot_main->setFont(font);
        comboBox_wave_type = new QComboBox(centralwidget);
        comboBox_wave_type->addItem(QString());
        comboBox_wave_type->addItem(QString());
        comboBox_wave_type->addItem(QString());
        comboBox_wave_type->addItem(QString());
        comboBox_wave_type->setObjectName(QString::fromUtf8("comboBox_wave_type"));
        comboBox_wave_type->setGeometry(QRect(675, 25, 115, 22));
        QFont font1;
        font1.setPointSize(12);
        comboBox_wave_type->setFont(font1);
        label_wave_type = new QLabel(centralwidget);
        label_wave_type->setObjectName(QString::fromUtf8("label_wave_type"));
        label_wave_type->setGeometry(QRect(550, 25, 110, 20));
        label_wave_type->setFont(font1);
        groupBox_layers = new QGroupBox(centralwidget);
        groupBox_layers->setObjectName(QString::fromUtf8("groupBox_layers"));
        groupBox_layers->setGeometry(QRect(550, 75, 350, 130));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_layers->sizePolicy().hasHeightForWidth());
        groupBox_layers->setSizePolicy(sizePolicy1);
        groupBox_layers->setMinimumSize(QSize(350, 130));
        groupBox_layers->setMaximumSize(QSize(350, 130));
        groupBox_layers->setFont(font1);
        label_vp_4 = new QLabel(groupBox_layers);
        label_vp_4->setObjectName(QString::fromUtf8("label_vp_4"));
        label_vp_4->setGeometry(QRect(250, 100, 50, 20));
        label_vp_4->setFont(font1);
        spinBox_vp1 = new QSpinBox(groupBox_layers);
        spinBox_vp1->setObjectName(QString::fromUtf8("spinBox_vp1"));
        spinBox_vp1->setGeometry(QRect(100, 50, 60, 20));
        spinBox_vp1->setFont(font1);
        spinBox_vp1->setMinimum(10);
        spinBox_vp1->setMaximum(20000);
        spinBox_vp1->setSingleStep(50);
        spinBox_vp1->setValue(2000);
        label_vp = new QLabel(groupBox_layers);
        label_vp->setObjectName(QString::fromUtf8("label_vp"));
        label_vp->setGeometry(QRect(25, 50, 40, 20));
        label_vp->setFont(font1);
        doubleSpinBox_dn2 = new QDoubleSpinBox(groupBox_layers);
        doubleSpinBox_dn2->setObjectName(QString::fromUtf8("doubleSpinBox_dn2"));
        doubleSpinBox_dn2->setGeometry(QRect(175, 100, 60, 20));
        doubleSpinBox_dn2->setFont(font1);
        doubleSpinBox_dn2->setMinimum(0.010000000000000);
        doubleSpinBox_dn2->setMaximum(10.000000000000000);
        doubleSpinBox_dn2->setSingleStep(0.500000000000000);
        doubleSpinBox_dn2->setValue(3.500000000000000);
        doubleSpinBox_dn1 = new QDoubleSpinBox(groupBox_layers);
        doubleSpinBox_dn1->setObjectName(QString::fromUtf8("doubleSpinBox_dn1"));
        doubleSpinBox_dn1->setGeometry(QRect(100, 100, 60, 20));
        doubleSpinBox_dn1->setFont(font1);
        doubleSpinBox_dn1->setMinimum(0.010000000000000);
        doubleSpinBox_dn1->setMaximum(10.000000000000000);
        doubleSpinBox_dn1->setSingleStep(0.500000000000000);
        doubleSpinBox_dn1->setValue(2.000000000000000);
        label_layer_2 = new QLabel(groupBox_layers);
        label_layer_2->setObjectName(QString::fromUtf8("label_layer_2"));
        label_layer_2->setGeometry(QRect(175, 25, 60, 20));
        label_layer_2->setFont(font1);
        label_vs = new QLabel(groupBox_layers);
        label_vs->setObjectName(QString::fromUtf8("label_vs"));
        label_vs->setGeometry(QRect(25, 75, 60, 20));
        label_vs->setFont(font1);
        label_vp_2 = new QLabel(groupBox_layers);
        label_vp_2->setObjectName(QString::fromUtf8("label_vp_2"));
        label_vp_2->setGeometry(QRect(250, 75, 40, 20));
        label_vp_2->setFont(font1);
        label_vp_3 = new QLabel(groupBox_layers);
        label_vp_3->setObjectName(QString::fromUtf8("label_vp_3"));
        label_vp_3->setGeometry(QRect(250, 50, 40, 20));
        label_vp_3->setFont(font1);
        label_layer_1 = new QLabel(groupBox_layers);
        label_layer_1->setObjectName(QString::fromUtf8("label_layer_1"));
        label_layer_1->setGeometry(QRect(100, 25, 60, 20));
        label_layer_1->setFont(font1);
        spinBox_vs2 = new QSpinBox(groupBox_layers);
        spinBox_vs2->setObjectName(QString::fromUtf8("spinBox_vs2"));
        spinBox_vs2->setGeometry(QRect(175, 75, 60, 20));
        spinBox_vs2->setFont(font1);
        spinBox_vs2->setMinimum(10);
        spinBox_vs2->setMaximum(20000);
        spinBox_vs2->setSingleStep(50);
        spinBox_vs2->setValue(2000);
        label_density = new QLabel(groupBox_layers);
        label_density->setObjectName(QString::fromUtf8("label_density"));
        label_density->setGeometry(QRect(25, 100, 60, 20));
        label_density->setFont(font1);
        spinBox_vp2 = new QSpinBox(groupBox_layers);
        spinBox_vp2->setObjectName(QString::fromUtf8("spinBox_vp2"));
        spinBox_vp2->setGeometry(QRect(175, 50, 60, 20));
        spinBox_vp2->setFont(font1);
        spinBox_vp2->setMinimum(10);
        spinBox_vp2->setMaximum(20000);
        spinBox_vp2->setSingleStep(50);
        spinBox_vp2->setValue(4000);
        spinBox_vs1 = new QSpinBox(groupBox_layers);
        spinBox_vs1->setObjectName(QString::fromUtf8("spinBox_vs1"));
        spinBox_vs1->setGeometry(QRect(100, 75, 60, 20));
        spinBox_vs1->setFont(font1);
        spinBox_vs1->setMinimum(10);
        spinBox_vs1->setMaximum(20000);
        spinBox_vs1->setSingleStep(50);
        spinBox_vs1->setValue(1500);
        groupBox_visual = new QGroupBox(centralwidget);
        groupBox_visual->setObjectName(QString::fromUtf8("groupBox_visual"));
        groupBox_visual->setGeometry(QRect(550, 295, 350, 130));
        sizePolicy1.setHeightForWidth(groupBox_visual->sizePolicy().hasHeightForWidth());
        groupBox_visual->setSizePolicy(sizePolicy1);
        groupBox_visual->setMinimumSize(QSize(350, 130));
        groupBox_visual->setMaximumSize(QSize(350, 130));
        groupBox_visual->setFont(font1);
        groupBox_parts = new QGroupBox(groupBox_visual);
        groupBox_parts->setObjectName(QString::fromUtf8("groupBox_parts"));
        groupBox_parts->setGeometry(QRect(10, 20, 101, 101));
        groupBox_parts->setFont(font1);
        checkBox_abs = new QCheckBox(groupBox_parts);
        checkBox_abs->setObjectName(QString::fromUtf8("checkBox_abs"));
        checkBox_abs->setGeometry(QRect(10, 75, 90, 20));
        checkBox_imag = new QCheckBox(groupBox_parts);
        checkBox_imag->setObjectName(QString::fromUtf8("checkBox_imag"));
        checkBox_imag->setGeometry(QRect(10, 50, 90, 20));
        checkBox_real = new QCheckBox(groupBox_parts);
        checkBox_real->setObjectName(QString::fromUtf8("checkBox_real"));
        checkBox_real->setGeometry(QRect(10, 25, 90, 20));
        groupBox_bound = new QGroupBox(groupBox_visual);
        groupBox_bound->setObjectName(QString::fromUtf8("groupBox_bound"));
        groupBox_bound->setGeometry(QRect(120, 20, 221, 101));
        label_angles = new QLabel(groupBox_bound);
        label_angles->setObjectName(QString::fromUtf8("label_angles"));
        label_angles->setGeometry(QRect(5, 50, 50, 20));
        label_angles->setFont(font1);
        label_angles->setAlignment(Qt::AlignCenter);
        label_r = new QLabel(groupBox_bound);
        label_r->setObjectName(QString::fromUtf8("label_r"));
        label_r->setGeometry(QRect(5, 75, 50, 20));
        label_r->setFont(font1);
        label_r->setAlignment(Qt::AlignCenter);
        label_bound_min = new QLabel(groupBox_bound);
        label_bound_min->setObjectName(QString::fromUtf8("label_bound_min"));
        label_bound_min->setGeometry(QRect(60, 25, 60, 20));
        label_bound_min->setFont(font1);
        label_bound_min->setAlignment(Qt::AlignCenter);
        spinBox_angle_max = new QSpinBox(groupBox_bound);
        spinBox_angle_max->setObjectName(QString::fromUtf8("spinBox_angle_max"));
        spinBox_angle_max->setGeometry(QRect(125, 50, 60, 20));
        spinBox_angle_max->setFont(font1);
        spinBox_angle_max->setMinimum(0);
        spinBox_angle_max->setMaximum(89);
        spinBox_angle_max->setSingleStep(5);
        spinBox_angle_max->setValue(85);
        spinBox_angle_min = new QSpinBox(groupBox_bound);
        spinBox_angle_min->setObjectName(QString::fromUtf8("spinBox_angle_min"));
        spinBox_angle_min->setGeometry(QRect(60, 50, 60, 20));
        spinBox_angle_min->setFont(font1);
        spinBox_angle_min->setMinimum(0);
        spinBox_angle_min->setMaximum(89);
        spinBox_angle_min->setSingleStep(5);
        spinBox_angle_min->setValue(0);
        doubleSpinBox_r_min = new QDoubleSpinBox(groupBox_bound);
        doubleSpinBox_r_min->setObjectName(QString::fromUtf8("doubleSpinBox_r_min"));
        doubleSpinBox_r_min->setGeometry(QRect(60, 75, 60, 20));
        doubleSpinBox_r_min->setFont(font1);
        doubleSpinBox_r_min->setMinimum(-5.000000000000000);
        doubleSpinBox_r_min->setMaximum(5.000000000000000);
        doubleSpinBox_r_min->setSingleStep(0.500000000000000);
        doubleSpinBox_r_min->setValue(-1.000000000000000);
        label_bound_resize = new QLabel(groupBox_bound);
        label_bound_resize->setObjectName(QString::fromUtf8("label_bound_resize"));
        label_bound_resize->setGeometry(QRect(185, 25, 31, 20));
        label_bound_resize->setFont(font1);
        doubleSpinBox_r_max = new QDoubleSpinBox(groupBox_bound);
        doubleSpinBox_r_max->setObjectName(QString::fromUtf8("doubleSpinBox_r_max"));
        doubleSpinBox_r_max->setGeometry(QRect(125, 75, 60, 20));
        doubleSpinBox_r_max->setFont(font1);
        doubleSpinBox_r_max->setMinimum(0.010000000000000);
        doubleSpinBox_r_max->setMaximum(10.000000000000000);
        doubleSpinBox_r_max->setSingleStep(0.500000000000000);
        doubleSpinBox_r_max->setValue(1.000000000000000);
        checkBox_angle = new QCheckBox(groupBox_bound);
        checkBox_angle->setObjectName(QString::fromUtf8("checkBox_angle"));
        checkBox_angle->setGeometry(QRect(195, 50, 16, 20));
        checkBox_r = new QCheckBox(groupBox_bound);
        checkBox_r->setObjectName(QString::fromUtf8("checkBox_r"));
        checkBox_r->setGeometry(QRect(195, 75, 16, 20));
        label_bound_max = new QLabel(groupBox_bound);
        label_bound_max->setObjectName(QString::fromUtf8("label_bound_max"));
        label_bound_max->setGeometry(QRect(125, 25, 60, 20));
        label_bound_max->setFont(font1);
        label_bound_max->setAlignment(Qt::AlignCenter);
        label_approx = new QLabel(centralwidget);
        label_approx->setObjectName(QString::fromUtf8("label_approx"));
        label_approx->setGeometry(QRect(550, 50, 110, 20));
        label_approx->setFont(font1);
        comboBox_approx = new QComboBox(centralwidget);
        comboBox_approx->setObjectName(QString::fromUtf8("comboBox_approx"));
        comboBox_approx->setGeometry(QRect(675, 50, 115, 22));
        comboBox_approx->setFont(font1);
        comboBox_approx->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        groupBox_calc = new QGroupBox(centralwidget);
        groupBox_calc->setObjectName(QString::fromUtf8("groupBox_calc"));
        groupBox_calc->setGeometry(QRect(550, 210, 350, 80));
        groupBox_calc->setFont(font1);
        checkBox_recalc = new QCheckBox(groupBox_calc);
        checkBox_recalc->setObjectName(QString::fromUtf8("checkBox_recalc"));
        checkBox_recalc->setGeometry(QRect(140, 50, 200, 20));
        checkBox_recalc->setFont(font1);
        pushButton_compute = new QPushButton(groupBox_calc);
        pushButton_compute->setObjectName(QString::fromUtf8("pushButton_compute"));
        pushButton_compute->setGeometry(QRect(140, 23, 191, 27));
        pushButton_compute->setFont(font1);
        label_r0 = new QLabel(groupBox_calc);
        label_r0->setObjectName(QString::fromUtf8("label_r0"));
        label_r0->setGeometry(QRect(25, 25, 20, 20));
        label_r0->setFont(font1);
        lineEdit_r = new QLineEdit(groupBox_calc);
        lineEdit_r->setObjectName(QString::fromUtf8("lineEdit_r"));
        lineEdit_r->setGeometry(QRect(50, 25, 81, 20));
        lineEdit_r->setReadOnly(true);
        label_g = new QLabel(groupBox_calc);
        label_g->setObjectName(QString::fromUtf8("label_g"));
        label_g->setGeometry(QRect(25, 50, 20, 20));
        label_g->setFont(font1);
        lineEdit_g = new QLineEdit(groupBox_calc);
        lineEdit_g->setObjectName(QString::fromUtf8("lineEdit_g"));
        lineEdit_g->setGeometry(QRect(50, 50, 81, 20));
        lineEdit_g->setReadOnly(true);
        groupBox_export = new QGroupBox(centralwidget);
        groupBox_export->setObjectName(QString::fromUtf8("groupBox_export"));
        groupBox_export->setGeometry(QRect(550, 430, 350, 60));
        groupBox_export->setFont(font1);
        groupBox_export->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_graph = new QPushButton(groupBox_export);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(10, 25, 100, 27));
        pushButton_window = new QPushButton(groupBox_export);
        pushButton_window->setObjectName(QString::fromUtf8("pushButton_window"));
        pushButton_window->setGeometry(QRect(125, 25, 100, 27));
        pushButton_table = new QPushButton(groupBox_export);
        pushButton_table->setObjectName(QString::fromUtf8("pushButton_table"));
        pushButton_table->setGeometry(QRect(240, 25, 100, 27));
        WindowMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 905, 21));
        WindowMain->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WindowMain->setStatusBar(statusbar);

        retranslateUi(WindowMain);

        QMetaObject::connectSlotsByName(WindowMain);
    } // setupUi

    void retranslateUi(QMainWindow *WindowMain)
    {
        WindowMain->setWindowTitle(QCoreApplication::translate("WindowMain", "Reflections", nullptr));
        comboBox_wave_type->setItemText(0, QCoreApplication::translate("WindowMain", "PP", nullptr));
        comboBox_wave_type->setItemText(1, QCoreApplication::translate("WindowMain", "PS", nullptr));
        comboBox_wave_type->setItemText(2, QCoreApplication::translate("WindowMain", "SP", nullptr));
        comboBox_wave_type->setItemText(3, QCoreApplication::translate("WindowMain", "SS", nullptr));

        label_wave_type->setText(QCoreApplication::translate("WindowMain", "Wave type", nullptr));
        groupBox_layers->setTitle(QCoreApplication::translate("WindowMain", "Layers parameters", nullptr));
        label_vp_4->setText(QCoreApplication::translate("WindowMain", "<html><head/><body><p>g/sm<span style=\" vertical-align:super;\">3</span></p></body></html>", nullptr));
        label_vp->setText(QCoreApplication::translate("WindowMain", "Vp", nullptr));
        label_layer_2->setText(QCoreApplication::translate("WindowMain", "Layer 2", nullptr));
        label_vs->setText(QCoreApplication::translate("WindowMain", "Vs", nullptr));
        label_vp_2->setText(QCoreApplication::translate("WindowMain", "m/s", nullptr));
        label_vp_3->setText(QCoreApplication::translate("WindowMain", "m/s", nullptr));
        label_layer_1->setText(QCoreApplication::translate("WindowMain", "Layer 1", nullptr));
        label_density->setText(QCoreApplication::translate("WindowMain", "Density", nullptr));
        groupBox_visual->setTitle(QCoreApplication::translate("WindowMain", "Visual parameters", nullptr));
        groupBox_parts->setTitle(QCoreApplication::translate("WindowMain", "Part to draw", nullptr));
        checkBox_abs->setText(QCoreApplication::translate("WindowMain", "absolute", nullptr));
        checkBox_imag->setText(QCoreApplication::translate("WindowMain", "imaginary", nullptr));
        checkBox_real->setText(QCoreApplication::translate("WindowMain", "real", nullptr));
        groupBox_bound->setTitle(QCoreApplication::translate("WindowMain", "Boundaries", nullptr));
        label_angles->setText(QCoreApplication::translate("WindowMain", "Angles", nullptr));
        label_r->setText(QCoreApplication::translate("WindowMain", "R", nullptr));
        label_bound_min->setText(QCoreApplication::translate("WindowMain", "min", nullptr));
        label_bound_resize->setText(QCoreApplication::translate("WindowMain", "auto", nullptr));
        checkBox_angle->setText(QString());
        checkBox_r->setText(QString());
        label_bound_max->setText(QCoreApplication::translate("WindowMain", "max", nullptr));
        label_approx->setText(QCoreApplication::translate("WindowMain", "Approximation", nullptr));
        comboBox_approx->setItemText(0, QCoreApplication::translate("WindowMain", "Aki-Richards", nullptr));
        comboBox_approx->setItemText(1, QCoreApplication::translate("WindowMain", "Shuye", nullptr));

        groupBox_calc->setTitle(QCoreApplication::translate("WindowMain", "Calculation", nullptr));
        checkBox_recalc->setText(QCoreApplication::translate("WindowMain", "Recalculate automatically", nullptr));
        pushButton_compute->setText(QCoreApplication::translate("WindowMain", "Calculate", nullptr));
        label_r0->setText(QCoreApplication::translate("WindowMain", "<html><head/><body><p><span style=\" font-size:12pt;\">R</span><span style=\" font-size:12pt; vertical-align:sub;\">0</span></p></body></html>", nullptr));
        label_g->setText(QCoreApplication::translate("WindowMain", "<html><head/><body><p><span style=\" font-size:12pt;\">G</span></p></body></html>", nullptr));
        groupBox_export->setTitle(QCoreApplication::translate("WindowMain", "Export", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("WindowMain", "Save graph", nullptr));
        pushButton_window->setText(QCoreApplication::translate("WindowMain", "Save window", nullptr));
        pushButton_table->setText(QCoreApplication::translate("WindowMain", "Save to table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowMain: public Ui_WindowMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWMAIN_H
