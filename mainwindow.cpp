#include "mainwindow.h"
#include "ecgwidget.h"  // Include the ECGWidget header file

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Set up your main window components and layout as needed

    // Define a set of points representing a normal heart ECG pattern
    QList<int> ecgPattern = {
       50,40,95,65,60,50,50,50,

    };

    // Create and add the ECG widget to the main window
    ecgWidget = new ECGWidget(this);
    ecgWidget->setECGData(ecgPattern);  // Set the ECG data
    setCentralWidget(ecgWidget);

    // Set up other components, menus, etc., as needed
}

MainWindow::~MainWindow() {
    // Clean up resources if needed
    delete ecgWidget;
}
