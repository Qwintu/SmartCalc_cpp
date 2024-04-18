/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *math;
    QLabel *x_label;
    QLabel *error_field;
    QPushButton *Button_7;
    QPushButton *Button_8;
    QPushButton *Button_9;
    QPushButton *Button_4;
    QPushButton *Button_5;
    QPushButton *Button_6;
    QPushButton *Button_1;
    QPushButton *Button_2;
    QPushButton *Button_3;
    QPushButton *Button_0;
    QPushButton *Button_dot;
    QPushButton *Button_plus;
    QPushButton *Button_minus;
    QPushButton *Button_dev;
    QPushButton *Button_mult;
    QPushButton *Button_equals;
    QPushButton *Button_br_open;
    QPushButton *Button_br_close;
    QPushButton *Button_u_minus;
    QPushButton *Button_asin;
    QPushButton *Button_x;
    QPushButton *Button_sqrt;
    QPushButton *Button_sin;
    QPushButton *Button_acos;
    QPushButton *Button_tan;
    QPushButton *Button_cos;
    QPushButton *Button_ln;
    QPushButton *Button_mod;
    QPushButton *Button_log10;
    QPushButton *Button_atan;
    QPushButton *Button_pow;
    QPushButton *Button_from_x;
    QPushButton *Button_clean;
    QPushButton *Button_to_x;
    QPushButton *Button_plot;
    QPushButton *Button_clean_x;
    QLabel *x_field;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *display;
    QWidget *credit;
    QDoubleSpinBox *loan_amount_SpinBox;
    QLabel *loan_amount_label;
    QComboBox *loan_term_comboBox;
    QLabel *loan_term_label;
    QDoubleSpinBox *interest_rate_SpinBox;
    QLabel *interest_rate_label;
    QLabel *type_label;
    QPushButton *calculate_credit_Button;
    QPlainTextEdit *schedule_plainTextEdit;
    QLabel *result_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *ann_radioButton;
    QRadioButton *diff_radioButton;
    QWidget *deposit;
    QLabel *dep_am_label;
    QLabel *dep_ir_label;
    QLabel *label_3;
    QLabel *dep_tax_label;
    QLabel *dep_period_label;
    QLabel *dep_capitalization_label;
    QDoubleSpinBox *dep_amount_SpinBox;
    QDoubleSpinBox *dep_Interest_rate_SpinBox;
    QComboBox *dep_term_comboBox;
    QDoubleSpinBox *dep_tax_rate_SpinBox;
    QComboBox *dep_Periodicity_comboBox;
    QComboBox *dep_capitalization_comboBox;
    QPushButton *dep_calc_pushButton;
    QLabel *label_7;
    QLabel *dep_last_day_label;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *dep_error_label;
    QLabel *dep_res_interest;
    QLabel *dep_res_total;
    QLabel *dep_res_tax;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(541, 592);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 20, 541, 541));
        math = new QWidget();
        math->setObjectName(QString::fromUtf8("math"));
        x_label = new QLabel(math);
        x_label->setObjectName(QString::fromUtf8("x_label"));
        x_label->setGeometry(QRect(10, 90, 30, 30));
        QFont font;
        font.setPointSize(16);
        x_label->setFont(font);
        error_field = new QLabel(math);
        error_field->setObjectName(QString::fromUtf8("error_field"));
        error_field->setGeometry(QRect(258, 90, 261, 30));
        Button_7 = new QPushButton(math);
        Button_7->setObjectName(QString::fromUtf8("Button_7"));
        Button_7->setGeometry(QRect(250, 270, 55, 55));
        Button_8 = new QPushButton(math);
        Button_8->setObjectName(QString::fromUtf8("Button_8"));
        Button_8->setGeometry(QRect(320, 270, 55, 55));
        Button_9 = new QPushButton(math);
        Button_9->setObjectName(QString::fromUtf8("Button_9"));
        Button_9->setGeometry(QRect(390, 270, 55, 55));
        Button_4 = new QPushButton(math);
        Button_4->setObjectName(QString::fromUtf8("Button_4"));
        Button_4->setGeometry(QRect(250, 330, 55, 55));
        Button_5 = new QPushButton(math);
        Button_5->setObjectName(QString::fromUtf8("Button_5"));
        Button_5->setGeometry(QRect(320, 330, 55, 55));
        Button_6 = new QPushButton(math);
        Button_6->setObjectName(QString::fromUtf8("Button_6"));
        Button_6->setGeometry(QRect(390, 330, 55, 55));
        Button_1 = new QPushButton(math);
        Button_1->setObjectName(QString::fromUtf8("Button_1"));
        Button_1->setGeometry(QRect(250, 390, 55, 55));
        Button_2 = new QPushButton(math);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));
        Button_2->setGeometry(QRect(320, 390, 55, 55));
        Button_3 = new QPushButton(math);
        Button_3->setObjectName(QString::fromUtf8("Button_3"));
        Button_3->setGeometry(QRect(390, 390, 55, 55));
        Button_0 = new QPushButton(math);
        Button_0->setObjectName(QString::fromUtf8("Button_0"));
        Button_0->setGeometry(QRect(250, 450, 127, 55));
        Button_dot = new QPushButton(math);
        Button_dot->setObjectName(QString::fromUtf8("Button_dot"));
        Button_dot->setGeometry(QRect(390, 450, 55, 55));
        Button_plus = new QPushButton(math);
        Button_plus->setObjectName(QString::fromUtf8("Button_plus"));
        Button_plus->setGeometry(QRect(470, 330, 55, 55));
        Button_minus = new QPushButton(math);
        Button_minus->setObjectName(QString::fromUtf8("Button_minus"));
        Button_minus->setGeometry(QRect(470, 390, 55, 55));
        Button_dev = new QPushButton(math);
        Button_dev->setObjectName(QString::fromUtf8("Button_dev"));
        Button_dev->setGeometry(QRect(470, 270, 55, 55));
        Button_mult = new QPushButton(math);
        Button_mult->setObjectName(QString::fromUtf8("Button_mult"));
        Button_mult->setGeometry(QRect(470, 210, 55, 55));
        Button_equals = new QPushButton(math);
        Button_equals->setObjectName(QString::fromUtf8("Button_equals"));
        Button_equals->setGeometry(QRect(470, 450, 55, 55));
        Button_br_open = new QPushButton(math);
        Button_br_open->setObjectName(QString::fromUtf8("Button_br_open"));
        Button_br_open->setGeometry(QRect(250, 210, 55, 55));
        Button_br_close = new QPushButton(math);
        Button_br_close->setObjectName(QString::fromUtf8("Button_br_close"));
        Button_br_close->setGeometry(QRect(320, 210, 55, 55));
        Button_u_minus = new QPushButton(math);
        Button_u_minus->setObjectName(QString::fromUtf8("Button_u_minus"));
        Button_u_minus->setGeometry(QRect(390, 210, 55, 55));
        Button_asin = new QPushButton(math);
        Button_asin->setObjectName(QString::fromUtf8("Button_asin"));
        Button_asin->setGeometry(QRect(10, 270, 55, 55));
        Button_x = new QPushButton(math);
        Button_x->setObjectName(QString::fromUtf8("Button_x"));
        Button_x->setGeometry(QRect(150, 390, 55, 55));
        Button_sqrt = new QPushButton(math);
        Button_sqrt->setObjectName(QString::fromUtf8("Button_sqrt"));
        Button_sqrt->setGeometry(QRect(80, 390, 55, 55));
        Button_sin = new QPushButton(math);
        Button_sin->setObjectName(QString::fromUtf8("Button_sin"));
        Button_sin->setGeometry(QRect(10, 210, 55, 55));
        Button_acos = new QPushButton(math);
        Button_acos->setObjectName(QString::fromUtf8("Button_acos"));
        Button_acos->setGeometry(QRect(80, 270, 55, 55));
        Button_tan = new QPushButton(math);
        Button_tan->setObjectName(QString::fromUtf8("Button_tan"));
        Button_tan->setGeometry(QRect(150, 210, 55, 55));
        Button_cos = new QPushButton(math);
        Button_cos->setObjectName(QString::fromUtf8("Button_cos"));
        Button_cos->setGeometry(QRect(80, 210, 55, 55));
        Button_ln = new QPushButton(math);
        Button_ln->setObjectName(QString::fromUtf8("Button_ln"));
        Button_ln->setGeometry(QRect(10, 330, 55, 55));
        Button_mod = new QPushButton(math);
        Button_mod->setObjectName(QString::fromUtf8("Button_mod"));
        Button_mod->setGeometry(QRect(150, 330, 55, 55));
        Button_log10 = new QPushButton(math);
        Button_log10->setObjectName(QString::fromUtf8("Button_log10"));
        Button_log10->setGeometry(QRect(80, 330, 55, 55));
        Button_atan = new QPushButton(math);
        Button_atan->setObjectName(QString::fromUtf8("Button_atan"));
        Button_atan->setGeometry(QRect(150, 270, 55, 55));
        Button_pow = new QPushButton(math);
        Button_pow->setObjectName(QString::fromUtf8("Button_pow"));
        Button_pow->setGeometry(QRect(10, 390, 55, 55));
        Button_from_x = new QPushButton(math);
        Button_from_x->setObjectName(QString::fromUtf8("Button_from_x"));
        Button_from_x->setGeometry(QRect(80, 140, 55, 55));
        Button_clean = new QPushButton(math);
        Button_clean->setObjectName(QString::fromUtf8("Button_clean"));
        Button_clean->setGeometry(QRect(250, 140, 55, 55));
        Button_to_x = new QPushButton(math);
        Button_to_x->setObjectName(QString::fromUtf8("Button_to_x"));
        Button_to_x->setGeometry(QRect(10, 140, 55, 55));
        Button_plot = new QPushButton(math);
        Button_plot->setObjectName(QString::fromUtf8("Button_plot"));
        Button_plot->setGeometry(QRect(470, 140, 55, 55));
        Button_clean_x = new QPushButton(math);
        Button_clean_x->setObjectName(QString::fromUtf8("Button_clean_x"));
        Button_clean_x->setGeometry(QRect(150, 140, 55, 55));
        x_field = new QLabel(math);
        x_field->setObjectName(QString::fromUtf8("x_field"));
        x_field->setGeometry(QRect(40, 90, 201, 30));
        x_field->setFont(font);
        scrollArea = new QScrollArea(math);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 20, 520, 70));
        scrollArea->setLayoutDirection(Qt::RightToLeft);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 518, 68));
        scrollArea->setWidget(scrollAreaWidgetContents);
        display = new QLabel(math);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(20, 0, 441, 31));
        QFont font1;
        font1.setPointSize(20);
        display->setFont(font1);
        display->setStyleSheet(QString::fromUtf8("padding-top: 5px "));
        display->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        tabWidget->addTab(math, QString());
        credit = new QWidget();
        credit->setObjectName(QString::fromUtf8("credit"));
        loan_amount_SpinBox = new QDoubleSpinBox(credit);
        loan_amount_SpinBox->setObjectName(QString::fromUtf8("loan_amount_SpinBox"));
        loan_amount_SpinBox->setGeometry(QRect(170, 20, 150, 25));
        loan_amount_SpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        loan_amount_SpinBox->setProperty("showGroupSeparator", QVariant(false));
        loan_amount_SpinBox->setMaximum(100000000.000000000000000);
        loan_amount_label = new QLabel(credit);
        loan_amount_label->setObjectName(QString::fromUtf8("loan_amount_label"));
        loan_amount_label->setGeometry(QRect(30, 20, 120, 25));
        loan_term_comboBox = new QComboBox(credit);
        loan_term_comboBox->setObjectName(QString::fromUtf8("loan_term_comboBox"));
        loan_term_comboBox->setGeometry(QRect(160, 60, 150, 25));
        loan_term_label = new QLabel(credit);
        loan_term_label->setObjectName(QString::fromUtf8("loan_term_label"));
        loan_term_label->setGeometry(QRect(30, 60, 120, 25));
        interest_rate_SpinBox = new QDoubleSpinBox(credit);
        interest_rate_SpinBox->setObjectName(QString::fromUtf8("interest_rate_SpinBox"));
        interest_rate_SpinBox->setGeometry(QRect(170, 100, 91, 25));
        interest_rate_SpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        interest_rate_SpinBox->setSingleStep(0.500000000000000);
        interest_rate_label = new QLabel(credit);
        interest_rate_label->setObjectName(QString::fromUtf8("interest_rate_label"));
        interest_rate_label->setGeometry(QRect(30, 100, 120, 25));
        type_label = new QLabel(credit);
        type_label->setObjectName(QString::fromUtf8("type_label"));
        type_label->setGeometry(QRect(30, 150, 120, 25));
        calculate_credit_Button = new QPushButton(credit);
        calculate_credit_Button->setObjectName(QString::fromUtf8("calculate_credit_Button"));
        calculate_credit_Button->setGeometry(QRect(170, 230, 100, 35));
        schedule_plainTextEdit = new QPlainTextEdit(credit);
        schedule_plainTextEdit->setObjectName(QString::fromUtf8("schedule_plainTextEdit"));
        schedule_plainTextEdit->setGeometry(QRect(10, 310, 511, 181));
        schedule_plainTextEdit->setReadOnly(true);
        result_label = new QLabel(credit);
        result_label->setObjectName(QString::fromUtf8("result_label"));
        result_label->setGeometry(QRect(10, 280, 511, 21));
        layoutWidget = new QWidget(credit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 150, 163, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ann_radioButton = new QRadioButton(layoutWidget);
        ann_radioButton->setObjectName(QString::fromUtf8("ann_radioButton"));

        verticalLayout->addWidget(ann_radioButton);

        diff_radioButton = new QRadioButton(layoutWidget);
        diff_radioButton->setObjectName(QString::fromUtf8("diff_radioButton"));

        verticalLayout->addWidget(diff_radioButton);

        tabWidget->addTab(credit, QString());
        deposit = new QWidget();
        deposit->setObjectName(QString::fromUtf8("deposit"));
        dep_am_label = new QLabel(deposit);
        dep_am_label->setObjectName(QString::fromUtf8("dep_am_label"));
        dep_am_label->setGeometry(QRect(30, 30, 121, 16));
        dep_ir_label = new QLabel(deposit);
        dep_ir_label->setObjectName(QString::fromUtf8("dep_ir_label"));
        dep_ir_label->setGeometry(QRect(30, 70, 101, 16));
        label_3 = new QLabel(deposit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 110, 121, 16));
        dep_tax_label = new QLabel(deposit);
        dep_tax_label->setObjectName(QString::fromUtf8("dep_tax_label"));
        dep_tax_label->setGeometry(QRect(30, 150, 91, 16));
        dep_period_label = new QLabel(deposit);
        dep_period_label->setObjectName(QString::fromUtf8("dep_period_label"));
        dep_period_label->setGeometry(QRect(30, 190, 141, 16));
        dep_capitalization_label = new QLabel(deposit);
        dep_capitalization_label->setObjectName(QString::fromUtf8("dep_capitalization_label"));
        dep_capitalization_label->setGeometry(QRect(30, 230, 151, 16));
        dep_amount_SpinBox = new QDoubleSpinBox(deposit);
        dep_amount_SpinBox->setObjectName(QString::fromUtf8("dep_amount_SpinBox"));
        dep_amount_SpinBox->setGeometry(QRect(220, 30, 111, 22));
        dep_amount_SpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dep_amount_SpinBox->setMaximum(99999999.989999994635582);
        dep_Interest_rate_SpinBox = new QDoubleSpinBox(deposit);
        dep_Interest_rate_SpinBox->setObjectName(QString::fromUtf8("dep_Interest_rate_SpinBox"));
        dep_Interest_rate_SpinBox->setGeometry(QRect(220, 70, 81, 22));
        dep_Interest_rate_SpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dep_Interest_rate_SpinBox->setMinimum(0.000000000000000);
        dep_Interest_rate_SpinBox->setSingleStep(0.100000000000000);
        dep_Interest_rate_SpinBox->setValue(0.000000000000000);
        dep_term_comboBox = new QComboBox(deposit);
        dep_term_comboBox->setObjectName(QString::fromUtf8("dep_term_comboBox"));
        dep_term_comboBox->setGeometry(QRect(210, 100, 131, 32));
        dep_tax_rate_SpinBox = new QDoubleSpinBox(deposit);
        dep_tax_rate_SpinBox->setObjectName(QString::fromUtf8("dep_tax_rate_SpinBox"));
        dep_tax_rate_SpinBox->setGeometry(QRect(220, 150, 81, 22));
        dep_tax_rate_SpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dep_tax_rate_SpinBox->setSingleStep(0.500000000000000);
        dep_tax_rate_SpinBox->setValue(13.000000000000000);
        dep_Periodicity_comboBox = new QComboBox(deposit);
        dep_Periodicity_comboBox->setObjectName(QString::fromUtf8("dep_Periodicity_comboBox"));
        dep_Periodicity_comboBox->setGeometry(QRect(210, 180, 131, 32));
        dep_capitalization_comboBox = new QComboBox(deposit);
        dep_capitalization_comboBox->setObjectName(QString::fromUtf8("dep_capitalization_comboBox"));
        dep_capitalization_comboBox->setGeometry(QRect(210, 220, 131, 32));
        dep_calc_pushButton = new QPushButton(deposit);
        dep_calc_pushButton->setObjectName(QString::fromUtf8("dep_calc_pushButton"));
        dep_calc_pushButton->setGeometry(QRect(230, 270, 100, 32));
        label_7 = new QLabel(deposit);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 330, 120, 20));
        dep_last_day_label = new QLabel(deposit);
        dep_last_day_label->setObjectName(QString::fromUtf8("dep_last_day_label"));
        dep_last_day_label->setGeometry(QRect(170, 330, 120, 20));
        label_9 = new QLabel(deposit);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 360, 120, 20));
        label_10 = new QLabel(deposit);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 390, 120, 20));
        label_11 = new QLabel(deposit);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 420, 120, 20));
        dep_error_label = new QLabel(deposit);
        dep_error_label->setObjectName(QString::fromUtf8("dep_error_label"));
        dep_error_label->setGeometry(QRect(30, 270, 151, 32));
        dep_res_interest = new QLabel(deposit);
        dep_res_interest->setObjectName(QString::fromUtf8("dep_res_interest"));
        dep_res_interest->setGeometry(QRect(170, 360, 120, 20));
        dep_res_total = new QLabel(deposit);
        dep_res_total->setObjectName(QString::fromUtf8("dep_res_total"));
        dep_res_total->setGeometry(QRect(170, 390, 120, 20));
        dep_res_tax = new QLabel(deposit);
        dep_res_tax->setObjectName(QString::fromUtf8("dep_res_tax"));
        dep_res_tax->setGeometry(QRect(170, 420, 120, 20));
        tabWidget->addTab(deposit, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 541, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc", nullptr));
        x_label->setText(QCoreApplication::translate("MainWindow", "x =", nullptr));
        Button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        Button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        Button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        Button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        Button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        Button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        Button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        Button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Button_dot->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        Button_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        Button_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Button_dev->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        Button_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        Button_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        Button_br_open->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        Button_br_close->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
#if QT_CONFIG(tooltip)
        Button_u_minus->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        Button_u_minus->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        Button_u_minus->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Button_u_minus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        Button_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        Button_x->setText(QCoreApplication::translate("MainWindow", "(x)", nullptr));
        Button_sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232x", nullptr));
        Button_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        Button_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
#if QT_CONFIG(tooltip)
        Button_tan->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        Button_tan->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        Button_tan->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Button_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        Button_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        Button_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        Button_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        Button_log10->setText(QCoreApplication::translate("MainWindow", "log10", nullptr));
        Button_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        Button_pow->setText(QCoreApplication::translate("MainWindow", "x^y", nullptr));
        Button_from_x->setText(QCoreApplication::translate("MainWindow", "x \342\206\222", nullptr));
#if QT_CONFIG(tooltip)
        Button_clean->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        Button_clean->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        Button_clean->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Button_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        Button_to_x->setText(QCoreApplication::translate("MainWindow", "x \342\206\220", nullptr));
        Button_plot->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        Button_clean_x->setText(QCoreApplication::translate("MainWindow", "xc", nullptr));
        x_field->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        display->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(math), QCoreApplication::translate("MainWindow", "MathCalc", nullptr));
        loan_amount_label->setText(QCoreApplication::translate("MainWindow", "Loan amount", nullptr));
        loan_term_label->setText(QCoreApplication::translate("MainWindow", "Loan term", nullptr));
        interest_rate_SpinBox->setSuffix(QCoreApplication::translate("MainWindow", " %", nullptr));
        interest_rate_label->setText(QCoreApplication::translate("MainWindow", "Interest rate, %", nullptr));
        type_label->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        calculate_credit_Button->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        result_label->setText(QCoreApplication::translate("MainWindow", "Total payment", nullptr));
        ann_radioButton->setText(QCoreApplication::translate("MainWindow", "Annuity payment", nullptr));
        diff_radioButton->setText(QCoreApplication::translate("MainWindow", "Differentiated payment", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(credit), QCoreApplication::translate("MainWindow", "CreditCalc", nullptr));
        dep_am_label->setText(QCoreApplication::translate("MainWindow", "Deposit amount", nullptr));
        dep_ir_label->setText(QCoreApplication::translate("MainWindow", "Interest rate", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Deposit term", nullptr));
        dep_tax_label->setText(QCoreApplication::translate("MainWindow", "Tax rate", nullptr));
        dep_period_label->setText(QCoreApplication::translate("MainWindow", "Periodicity of payments", nullptr));
        dep_capitalization_label->setText(QCoreApplication::translate("MainWindow", "Capitalization of interest", nullptr));
        dep_calc_pushButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Maturity Date:", nullptr));
        dep_last_day_label->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Interest Earned", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Maturity amount:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Taxes", nullptr));
        dep_error_label->setText(QString());
        dep_res_interest->setText(QString());
        dep_res_total->setText(QString());
        dep_res_tax->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(deposit), QCoreApplication::translate("MainWindow", "DepositCalc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
