#include "mainwindow.h"
#include "ecgwidget.h"  // Include the ECGWidget header file
#include "ledwidget.h"
#include "ui_mainwindow.h"
#include "selftest.h"
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

    selfTestModule = new SelfTest();

    //set selfcheck toggle to green by default
    ui->electrode_ST->setStyleSheet("background-color:green");
    ui->battery_ST->setStyleSheet("background-color:green");
    ui->software_ST->setStyleSheet("background-color:green");
    ui->hardware_ST->setStyleSheet("background-color:green");


    // Create and add the ECG widget to the main window

//    ecgWidget = new ECGWidget(this);
//    ecgWidget->setECGData(VT);  // Set the ECG data
//    ui->ecgLayout->addWidget(ecgWidget);

    // Set up other components, menus, etc., as needed

    //set up LED lights for different stages
    QColor black = Qt::black;
    ui->callLight->setColor(black);
    ui->okLight->setColor(black);
    ui->heartLight->setColor(black);
    ui->cprLight->setColor(black);
    ui->padLight->setColor(black);
    ui->shockLight->setColor(black);
    ui->selfTestCheckLight->setColor(black);
    ui->selfTestCheckLight->setFixedSize(100,50);


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
    ui->ecgGraphLabel->setText("Normal Sinus Rhythm");

}


//replace ecgLayout with ventricular fribillation ECG
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
    ui->ecgGraphLabel->setText("Ventricular Fribillation");
}

//replace ecgLayout with ventricular tachycardia ECG
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
    ui->ecgGraphLabel->setText("Ventricular Tachycardia");
}

//replace ecgLayout with flatline ECG
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
    ui->ecgGraphLabel->setText("Flatline");
}

//replace ecgLayout with Asystole ECG
void MainWindow::on_asystoleECG_clicked()
{
    QList<int> AsystoleEcgPattern = {
      50,55,50,50,55,52,50,50,55,50,50,55,52,50,50,45,50,55,50,50,55,52,50,50,55,50,50,55,52,50
    };


    clearLayout(ui->ecgLayout);
    ui->ecgLayout->removeWidget(ecgWidget);
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(AsystoleEcgPattern);  // Set the ECG data
    ui->ecgLayout->addWidget(ecgWidget);
    ui->ecgGraphLabel->setText("Asystole");
}

void MainWindow::on_resetECG_clicked()
{

    clearLayout(ui->ecgLayout);
    ui->ecgGraphLabel->setText("");

}



//If electrode fail self check test is toggled change colour, perform self test.
void MainWindow::on_electrode_ST_toggled(bool checked)
{
    //set selftest variables status and perform self test, then change self test led colour
    if (checked == true){
        ui->electrode_ST->setStyleSheet("background-color:red;");
        selfTestModule->setElectrodeStatus(false);
    }else{
        ui->electrode_ST->setStyleSheet("background-color:green;");
        selfTestModule->setElectrodeStatus(true);
    }

    if(selfTestModule->performSelfTest()==true){
        ui->selfTestCheckLight->setColor(Qt::green);
        ui->label_display->setText("Self Test SUCCESSFUL");
    }else{
        ui->selfTestCheckLight->setColor(Qt::red);
        ui->label_display->setText("Self Test FAILED");
    }

}


//If battery fail self check test is toggled change colour
void MainWindow::on_battery_ST_toggled(bool checked)
{
    if (checked == true){
        ui->battery_ST->setStyleSheet("background-color:red;");
        selfTestModule->setBatteryStatus(false);
    }else{
        ui->battery_ST->setStyleSheet("background-color:green;");
        selfTestModule->setBatteryStatus(true);
    }

    if(selfTestModule->performSelfTest()==true){
        ui->selfTestCheckLight->setColor(Qt::green);
        ui->label_display->setText("Self Test SUCCESSFUL");
    }else{
        ui->selfTestCheckLight->setColor(Qt::red);
        ui->label_display->setText("Self Test FAILED");
    }
}

//If software fail self check test is toggled change colour
void MainWindow::on_software_ST_toggled(bool checked)
{
    if (checked == true){
        ui->software_ST->setStyleSheet("background-color:red;");
        selfTestModule->setSoftwareStatus(false);
    }else{
        ui->software_ST->setStyleSheet("background-color:green;");
        selfTestModule->setSoftwareStatus(true);
    }

    if(selfTestModule->performSelfTest()==true){
        ui->selfTestCheckLight->setColor(Qt::green);
        ui->label_display->setText("Self Test SUCCESSFUL");
    }else{
        ui->selfTestCheckLight->setColor(Qt::red);
        ui->label_display->setText("Self Test FAILED");
    }
}
//If hardware fail self check test is toggled change colour

void MainWindow::on_hardware_ST_toggled(bool checked)
{

    if (checked == true){
        ui->hardware_ST->setStyleSheet("background-color:red;");
        selfTestModule->setHardwareStatus(false);
    }else{
        ui->hardware_ST->setStyleSheet("background-color:green;");
        selfTestModule->setHardwareStatus(true);
    }

    if(selfTestModule->performSelfTest()==true){
        ui->selfTestCheckLight->setColor(Qt::green);
        ui->label_display->setText("Self Test SUCCESSFUL");
    }else{
        ui->selfTestCheckLight->setColor(Qt::red);
        ui->label_display->setText("Self Test FAILED");
    }
}


void MainWindow::on_toggleLEDs_toggled(bool checked)
{

    QColor red = Qt::red;
    QColor black = Qt::black;
    if(checked == true){
        ui->callLight->setColor(red);
        ui->okLight->setColor(red);
        ui->heartLight->setColor(red);
        ui->cprLight->setColor(red);
        ui->padLight->setColor(red);
        ui->shockLight->setColor(red);

    }else{
        ui->callLight->setColor(black);
        ui->okLight->setColor(black);
        ui->heartLight->setColor(black);
        ui->cprLight->setColor(black);
        ui->padLight->setColor(black);
        ui->shockLight->setColor(black);
    }

}


