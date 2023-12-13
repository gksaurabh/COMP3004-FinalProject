#include "mainwindow.h"
#include "ecgwidget.h"  // Include the ECGWidget header file
#include "ledwidget.h"
#include "ui_mainwindow.h"
#include "selftest.h"

#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QTimer>
//#include <string>
//using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    // Set up your main window components and layout as needed
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(changeTimer()));

    ui->timerDisplay->setStyleSheet("background-color: black");
    ui->shockDisplay->setStyleSheet("background-color: black");
    ui->cpr_count_Display->setStyleSheet("background-color: black");
    ui->batteryDisplay->setStyleSheet("background-color: black");
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


    //disable buttons not needed.
    ui->analyzeHR_button->setEnabled(false);
    ui->applyPad_Button->setEnabled(false);
    ui->pushCPR_Button->setEnabled(false);


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
    ui->ecgGraphLabel->setText("Ventricular Fribrillation");
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



void MainWindow::on_onOffButton_toggled(bool checked)
{

    if(checked == true){
        runAED();
    }


}

void MainWindow::changeTimer()
{
    lcdTimer+=1;
    ui->timerDisplay->display(lcdTimer);
}

void MainWindow::runAED()
{
    QString ecgRhythm = ui->ecgGraphLabel->text();
    ui->selfTestCheckLight->setColor(Qt::black);
    timer->start(1000);

    qDebug() <<  ui->ecgGraphLabel->text();
    qDebug() << ecgRhythm;


    ui->label_display->setText("AED Machine On");
    delay(5);
    ui->label_display->setText("Performing Self Check");
    delay(5);

    if(performSelfCheck() == true){
        ui->label_display->setText("Self Check PASSED");
        delay(5);
        ui->label_display->setText("Check patient");
        ui->okLight->setColor(Qt::red);
        delay(10);
        ui->okLight->setColor(Qt::black);
        ui->label_display->setText("Call 911");
        ui->callLight->setColor(Qt::red);
        delay(10);
        ui->callLight->setColor(Qt::black);
        ui->label_display->setText("Place Electrode Pads");
        ui->padLight->setColor(Qt::red);
        ui->applyPad_Button->setEnabled(true);
        delay(10);


    }else{
        ui->label_display->setText("Self Test FAILED, Call 911");
    }

}

void::MainWindow::delay(int seconds)
{
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

bool MainWindow::performSelfCheck()
{
    bool hardware = ui->hardware_ST->isChecked();
    bool software = ui->software_ST->isChecked();
    bool battery = ui->battery_ST->isChecked();
    bool electrode = ui->electrode_ST->isChecked();

    if((hardware == false) && (software == false) && (battery == false) && (electrode == false)){
        ui->selfTestCheckLight->setColor(Qt::green);
        return true;
    }
    else{
        ui->selfTestCheckLight->setColor(Qt::red);
        return false;
    }
}

void MainWindow::shockPatient(int cycles)
{
    for(int i = 0; i < cycles; i++){
        delay(10);
        ui->label_display->setText("SHOCKING PATIENT");
        shockCount+=1;
        ui->shockDisplay->display(shockCount);
        delay(5);
        ui->label_display->setText("Analyzing Heart Rate");
        delay(5);
        ui->label_display->setText("Please stay back SHOCK NEEDED");

    }
}

void MainWindow::on_applyPad_Button_clicked()
{
    //set LED lights to the correct stage.
    QColor black = Qt::black;
    QColor red = Qt::red;
    ui->callLight->setColor(black);
    ui->okLight->setColor(black);
    ui->heartLight->setColor(black);
    ui->cprLight->setColor(black);
    ui->padLight->setColor(red);
    ui->shockLight->setColor(black);

    QString applySelection = ui->ddlist_applyPad->currentText();
    if(applySelection.compare("Proper Application") == 0){

        //move lights to next stage
        ui->padLight->setColor(black);
        ui->shockLight->setColor(red);

        ui->label_display->setText("Please Stand back");
        delay(10);
        ui->label_display->setText("(Select HR then) Press Analyze");
        ui->analyzeHR_button->setEnabled(true);
    }else{
        ui->label_display->setText("Apply Pads Properly");
    }

}


void MainWindow::on_analyzeHR_button_clicked()
{
    //set LED lights to the correct stage.
    QColor black = Qt::black;
    QColor red = Qt::red;
    ui->callLight->setColor(black);
    ui->okLight->setColor(black);
    ui->heartLight->setColor(red);
    ui->cprLight->setColor(black);
    ui->padLight->setColor(black);
    ui->shockLight->setColor(black);

    ui->applyPad_Button->setEnabled(false);

    ui->label_display->setText("Analyzing heartbeat");


    QString applySelection = ui->ddlist_applyPad->currentText();
    if(applySelection.compare("Proper Application") == 0){
        QString ecgRhythm = ui->ecgGraphLabel->text();

        if(ecgRhythm.compare("Normal Sinus Rhythm") == 0){
            ui->shockLight->setColor(black);
            delay(10);
            ui->label_display->setText("Patient is OK, Normal Rhtyhm");
            delay(10);
            ui->label_display->setText("NO SHOCK and NO CPR");
            delay(10);
            ui->label_display->setText("Wait for Paramedics");
        }
        else if(ecgRhythm.compare("Ventricular Fribrillation") == 0){
             delay(10);
             ui->heartLight->setColor(black);
             ui->shockLight->setColor(red);

             ui->label_display->setText("Patient is in Fibirillation");
             delay(10);
             ui->label_display->setText("Please stand back SHOCK NEEDED");
             shockPatient(4);
             ui->label_display->setText("Normal Rhythm Detected");
             on_normalECG_clicked();
             delay(10);
             ui->label_display->setText("Wait for Paramedics");


        }
        else if(ecgRhythm.compare("Ventricular Tachycardia") == 0){
            delay(10);
            ui->heartLight->setColor(black);
            ui->shockLight->setColor(red);

            ui->label_display->setText("Patient is in Tachycardia");
            delay(10);
            ui->label_display->setText("Please stand back SHOCK NEEDED");
            shockPatient(2);
            ui->label_display->setText("Normal Rhythm Detected");
            on_normalECG_clicked();
            delay(10);
            ui->label_display->setText("Wait for Paramedics");
            ui->heartLight->setColor(red);
            ui->shockLight->setColor(black);


        }
        else if(ecgRhythm.compare("Flatline") == 0){
            delay(10);
            ui->heartLight->setColor(black);
            ui->cprLight->setColor(red);

            ui->label_display->setText("PERFORM CPR");
            ui->pushCPR_Button->setEnabled(true);


        }
        else if(ecgRhythm.compare("Asystole") == 0){
            delay(10);
            ui->heartLight->setColor(black);
            ui->shockLight->setColor(red);


            ui->label_display->setText("PERFORM CPR");
            ui->pushCPR_Button->setEnabled(true);
        }
    }
}


void MainWindow::on_pushCPR_Button_clicked()
{
    int compressionDepth = ui->ddlist_cprDepth->currentIndex();
    if(compressionDepth < 5){
        ui->label_display->setText("PUSH HARDER (at least 5cm depth)");
    }
    else{
        ui->label_display->setText("GOOD PUSH");
        pushCount+=1;
        ui->cpr_count_Display->display(pushCount);
        if(pushCount%30 == 0){
            ui->label_display->setText("Perform Mouth to Mouth. 2 Breaths");
            ui->pushCPR_Button->setEnabled(false);
            delay(10);
            ui->label_display->setText("Repeat if patient is not revived.");
            ui->pushCPR_Button->setEnabled(true);
        }
        else{
            if(pushCount == 42){
                ui->pushCPR_Button->setEnabled(false);
                on_normalECG_clicked();
                ui->label_display->setText("Normal Rhythm Detected");
                delay(10);
                ui->label_display->setText("Wait for Paramedics");
                ui->heartLight->setColor(Qt::red);
                ui->cprLight->setColor(Qt::black);

            }
        }
    }

}

