#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ECGWidget;  // Forward declaration

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    ECGWidget *ecgWidget;  // Pointer to the ECG widget
};

#endif // MAINWINDOW_H
