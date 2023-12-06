#include "mainwindow.h"
#include "ecgwidget.h"  // Include the ECGWidget header file

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Set up your main window components and layout as needed

    // Define a set of points representing a normal heart ECG pattern
    QList<int> normalEcgPattern = {
       50,40,95,65,60,50,50,50,50,40,95,65,60,50,50,50,50,40,95,65,60,50,50,50,
    };
    QList<int> flatlineEcgPattern = {
      50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
    };
    QList<int> AsystoleEcgPattern = {
      50,55,50,50,55,52,50,50,55,50,50,55,52,50,50,45,50,55,50,50,55,52,50,50,55,50,50,55,52,50
    };
    QList<int> VF = {
      80,75,40,80,35,92,70,40,25,10,50,80,75,40,80,35,92,70,40,25,10,50,80,75,40,
    };

    QList<int> VT = {
     30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,30,30,30,35,40,45,50,55,60,65,70,75,80,80,80,80,75,70,65,60,55,50,45,40,35,30,
    };
    // Create and add the ECG widget to the main window
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(VT);  // Set the ECG data
    setCentralWidget(ecgWidget);

    // Set up other components, menus, etc., as needed
}

MainWindow::~MainWindow() {
    // Clean up resources if needed
    delete ecgWidget;
}
