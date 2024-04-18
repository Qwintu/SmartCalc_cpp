/********************************************************************************
** Form generated from reading UI file 'plotwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWINDOW_H
#define UI_PLOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_close_plot;
    QPushButton *Button_replot;
    QSpinBox *spinBox_x_min;
    QLabel *label;
    QSpinBox *spinBox_x_max;
    QLabel *label_2;
    QSpinBox *spinBox_y_min;
    QLabel *label_3;
    QSpinBox *spinBox_y_max;
    QLabel *label_4;
    QWidget *gridLayoutWidget;
    QGridLayout *plot_widget;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spinBox_x_range_max;
    QLabel *label_8;
    QSpinBox *spinBox_x_range_min;
    QLabel *label_9;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radio_dots;
    QRadioButton *radio_line;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radio_deg;
    QRadioButton *radio_rad;
    QLabel *func_label;

    void setupUi(QDialog *PlotWindow)
    {
        if (PlotWindow->objectName().isEmpty())
            PlotWindow->setObjectName(QString::fromUtf8("PlotWindow"));
        PlotWindow->resize(811, 811);
        horizontalLayoutWidget = new QWidget(PlotWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 791, 83));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(horizontalLayoutWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 661, 69));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_close_plot = new QPushButton(horizontalLayoutWidget);
        Button_close_plot->setObjectName(QString::fromUtf8("Button_close_plot"));

        horizontalLayout->addWidget(Button_close_plot);

        horizontalLayout->setStretch(0, 10);
        Button_replot = new QPushButton(PlotWindow);
        Button_replot->setObjectName(QString::fromUtf8("Button_replot"));
        Button_replot->setGeometry(QRect(690, 770, 101, 31));
        spinBox_x_min = new QSpinBox(PlotWindow);
        spinBox_x_min->setObjectName(QString::fromUtf8("spinBox_x_min"));
        spinBox_x_min->setGeometry(QRect(230, 750, 81, 21));
        spinBox_x_min->setMinimum(-1000000);
        spinBox_x_min->setMaximum(1000000);
        spinBox_x_min->setValue(-100);
        label = new QLabel(PlotWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 750, 41, 21));
        spinBox_x_max = new QSpinBox(PlotWindow);
        spinBox_x_max->setObjectName(QString::fromUtf8("spinBox_x_max"));
        spinBox_x_max->setGeometry(QRect(390, 750, 81, 21));
        spinBox_x_max->setMinimum(-1000000);
        spinBox_x_max->setMaximum(1000000);
        spinBox_x_max->setValue(100);
        label_2 = new QLabel(PlotWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 750, 41, 21));
        spinBox_y_min = new QSpinBox(PlotWindow);
        spinBox_y_min->setObjectName(QString::fromUtf8("spinBox_y_min"));
        spinBox_y_min->setGeometry(QRect(230, 780, 81, 21));
        spinBox_y_min->setMinimum(-1000000);
        spinBox_y_min->setMaximum(1000000);
        spinBox_y_min->setValue(-30);
        label_3 = new QLabel(PlotWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 780, 41, 21));
        spinBox_y_max = new QSpinBox(PlotWindow);
        spinBox_y_max->setObjectName(QString::fromUtf8("spinBox_y_max"));
        spinBox_y_max->setGeometry(QRect(390, 780, 81, 21));
        spinBox_y_max->setMinimum(-1000000);
        spinBox_y_max->setValue(30);
        label_4 = new QLabel(PlotWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 780, 41, 21));
        gridLayoutWidget = new QWidget(PlotWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 90, 791, 621));
        plot_widget = new QGridLayout(gridLayoutWidget);
        plot_widget->setObjectName(QString::fromUtf8("plot_widget"));
        plot_widget->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(PlotWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 720, 71, 16));
        QFont font;
        font.setPointSize(14);
        label_5->setFont(font);
        label_6 = new QLabel(PlotWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 720, 111, 16));
        label_6->setFont(font);
        label_7 = new QLabel(PlotWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 720, 81, 16));
        label_7->setFont(font);
        spinBox_x_range_max = new QSpinBox(PlotWindow);
        spinBox_x_range_max->setObjectName(QString::fromUtf8("spinBox_x_range_max"));
        spinBox_x_range_max->setGeometry(QRect(570, 780, 81, 21));
        spinBox_x_range_max->setMinimum(-1000000);
        spinBox_x_range_max->setMaximum(1000000);
        spinBox_x_range_max->setValue(500);
        label_8 = new QLabel(PlotWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 780, 41, 21));
        spinBox_x_range_min = new QSpinBox(PlotWindow);
        spinBox_x_range_min->setObjectName(QString::fromUtf8("spinBox_x_range_min"));
        spinBox_x_range_min->setGeometry(QRect(570, 750, 81, 21));
        spinBox_x_range_min->setMinimum(-1000000);
        spinBox_x_range_min->setMaximum(1000000);
        spinBox_x_range_min->setValue(-500);
        label_9 = new QLabel(PlotWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(520, 750, 41, 21));
        layoutWidget = new QWidget(PlotWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 740, 53, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radio_dots = new QRadioButton(layoutWidget);
        radio_dots->setObjectName(QString::fromUtf8("radio_dots"));
        radio_dots->setChecked(true);

        verticalLayout->addWidget(radio_dots);

        radio_line = new QRadioButton(layoutWidget);
        radio_line->setObjectName(QString::fromUtf8("radio_line"));
        radio_line->setChecked(false);

        verticalLayout->addWidget(radio_line);

        layoutWidget1 = new QWidget(PlotWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 740, 53, 71));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radio_deg = new QRadioButton(layoutWidget1);
        radio_deg->setObjectName(QString::fromUtf8("radio_deg"));
        radio_deg->setChecked(true);

        verticalLayout_2->addWidget(radio_deg);

        radio_rad = new QRadioButton(layoutWidget1);
        radio_rad->setObjectName(QString::fromUtf8("radio_rad"));
        radio_rad->setChecked(false);

        verticalLayout_2->addWidget(radio_rad);

        func_label = new QLabel(PlotWindow);
        func_label->setObjectName(QString::fromUtf8("func_label"));
        func_label->setGeometry(QRect(0, 60, 661, 61));
        func_label->setFont(font);

        retranslateUi(PlotWindow);
        QObject::connect(Button_close_plot, &QPushButton::clicked, PlotWindow, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(PlotWindow);
    } // setupUi

    void retranslateUi(QDialog *PlotWindow)
    {
        PlotWindow->setWindowTitle(QCoreApplication::translate("PlotWindow", "Dialog", nullptr));
        Button_close_plot->setText(QCoreApplication::translate("PlotWindow", "close", nullptr));
        Button_replot->setText(QCoreApplication::translate("PlotWindow", "Replot", nullptr));
        label->setText(QCoreApplication::translate("PlotWindow", "x min", nullptr));
        label_2->setText(QCoreApplication::translate("PlotWindow", "x max", nullptr));
        label_3->setText(QCoreApplication::translate("PlotWindow", "y max", nullptr));
        label_4->setText(QCoreApplication::translate("PlotWindow", "y min", nullptr));
        label_5->setText(QCoreApplication::translate("PlotWindow", "Draw with", nullptr));
        label_6->setText(QCoreApplication::translate("PlotWindow", "Visible area", nullptr));
        label_7->setText(QCoreApplication::translate("PlotWindow", "x range", nullptr));
        label_8->setText(QCoreApplication::translate("PlotWindow", "x max", nullptr));
        label_9->setText(QCoreApplication::translate("PlotWindow", "x min", nullptr));
        radio_dots->setText(QCoreApplication::translate("PlotWindow", "dots", nullptr));
        radio_line->setText(QCoreApplication::translate("PlotWindow", "line", nullptr));
        radio_deg->setText(QCoreApplication::translate("PlotWindow", "DEG", nullptr));
        radio_rad->setText(QCoreApplication::translate("PlotWindow", "RAD", nullptr));
        func_label->setText(QCoreApplication::translate("PlotWindow", "f(x) = ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotWindow: public Ui_PlotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWINDOW_H
