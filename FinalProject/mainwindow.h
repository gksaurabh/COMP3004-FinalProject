#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "selftest.h"

#include <QMainWindow>
#include <QGraphicsScene>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    ECGWidget *ecgWidget;  // Pointer to the ECG widget
    SelfTest *selfTestModule; // Pointer to our Self Test module


};

#endif // MAINWINDOW_H
