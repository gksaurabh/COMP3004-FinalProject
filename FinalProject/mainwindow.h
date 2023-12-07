#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_vtECG_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    ECGWidget *ecgWidget;  // Pointer to the ECG widget

};

#endif // MAINWINDOW_H
