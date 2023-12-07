#include "mainwindow.h"
#include "ecgwidget.h"  // Include the ECGWidget header file
#include "ledwidget.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    // Set up your main window components and layout as needed
    ui->setupUi(this);
    // Define a set of points representing a normal heart ECG pattern

    QList<int> flatlineEcgPattern = {
      50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
    };
    QList<int> AsystoleEcgPattern = {
      50,55,50,50,55,52,50,50,55,50,50,55,52,50,50,45,50,55,50,50,55,52,50,50,55,50,50,55,52,50
    };

    QList<int> VT = {
     30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,
    };
    // Create and add the ECG widget to the main window

    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(VT);  // Set the ECG data
    ui->ecgLayout->addWidget(ecgWidget);

    // Set up other components, menus, etc., as needed
    LedWidget *ledLight = new LedWidget(this);
    ui->heartLED->addWidget(ledLight);



}

MainWindow::~MainWindow() {
    // Clean up resources if needed
    delete ecgWidget;
    delete ui;
}

//The following deletes anything that is in a layout.
void clearLayout(QLayout *layout) {
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}

//replace ecgLayout with normal sinus rhythym ECG
void MainWindow::on_normalECG_clicked()
{
    QList<int> normalEcgPattern = {
       50,40,95,65,60,50,50,50,50,40,95,65,60,50,50,50,50,40,95,65,60,50,50,50,
    };
    clearLayout(ui->ecgLayout);
    ui->ecgLayout->removeWidget(ecgWidget);
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(normalEcgPattern);  // Set the ECG data
    ui->ecgLayout->addWidget(ecgWidget);

}



void MainWindow::on_vfECG_clicked()
{
    QList<int> VF = {
      80,75,40,80,35,92,70,40,25,10,50,80,75,40,80,35,92,70,40,25,10,50,80,75,40,
    };
    clearLayout(ui->ecgLayout);
    ui->ecgLayout->removeWidget(ecgWidget);
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(VF);  // Set the ECG data
    ui->ecgLayout->addWidget(ecgWidget);
}


void MainWindow::on_vtECG_clicked()
{
    QList<int> VT = {
     30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,
    };
    clearLayout(ui->ecgLayout);
    ui->ecgLayout->removeWidget(ecgWidget);
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(VT);  // Set the ECG data
    ui->ecgLayout->addWidget(ecgWidget);
}


void MainWindow::on_flatlineECG_clicked()
{
    QList<int> flatlineEcgPattern = {
      50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
    };

    clearLayout(ui->ecgLayout);
    ui->ecgLayout->removeWidget(ecgWidget);
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(flatlineEcgPattern);  // Set the ECG data
    ui->ecgLayout->addWidget(ecgWidget);
}


void MainWindow::on_vtECG_2_clicked()
{
    QList<int> AsystoleEcgPattern = {
      50,55,50,50,55,52,50,50,55,50,50,55,52,50,50,45,50,55,50,50,55,52,50,50,55,50,50,55,52,50
    };


    clearLayout(ui->ecgLayout);
    ui->ecgLayout->removeWidget(ecgWidget);
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(AsystoleEcgPattern);  // Set the ECG data
    ui->ecgLayout->addWidget(ecgWidget);
}

