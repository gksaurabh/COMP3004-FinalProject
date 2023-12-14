#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "selftest.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ECGWidget;  // Forward declaration

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_normalECG_clicked();

    void on_vfECG_clicked();

    void on_vtECG_clicked();

    void on_flatlineECG_clicked();

    void on_resetECG_clicked();

    void on_asystoleECG_clicked();

    void on_electrode_ST_toggled(bool checked);

    void on_battery_ST_toggled(bool checked);

    void on_software_ST_toggled(bool checked);

    void on_hardware_ST_toggled(bool checked);

    void on_toggleLEDs_toggled(bool checked);

    void on_onButton_toggled(bool checked);
    void changeTimer();



    void on_applyPad_Button_clicked();

    void on_analyzeHR_button_clicked();

    void on_pushCPR_Button_clicked();

    void on_OffButton_toggled(bool checked);

    void on_adultScenario_button_clicked();

    void on_childScenario_Button_clicked();

    void on_replaceBattery_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    ECGWidget *ecgWidget;  // Pointer to the ECG widget
    SelfTest *selfTestModule; // Pointer to our Self Test module
    QTimer *timer;
    Battery *battery = new Battery();
    int lcdTimer = 0;
    int pushCount = 0;
    int shockCount = 0;

    void runAED();
    void delay(int seconds);
    bool performSelfCheck();
    void shockPatient(int cycles);
    void reset();
    void depleteBattery(int val);


};

#endif // MAINWINDOW_H
