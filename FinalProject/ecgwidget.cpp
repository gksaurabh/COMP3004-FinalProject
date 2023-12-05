#include "ecgwidget.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>
ECGWidget::ECGWidget(QWidget *parent)
    : QWidget(parent) {
    // Set up a timer to update the ECG waveform
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ECGWidget::updateECG);
    timer->start(300); // Update every 50 milliseconds
}

void ECGWidget::setECGData(const QList<int> &data) {
    ecgData = data;
    qDebug() << ecgData;
    update();  // Trigger a repaint with the new data
}

void ECGWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Draw the ECG waveform
    painter.setPen(QPen(Qt::red, 2));
    int stepSize = width() / (ecgData.size() - 1);
    for (int i = 1; i < ecgData.size(); ++i) {
        int x1 = (i - 1) * stepSize;
        int y1 = height() - (height() * ecgData[i - 1]) / 100;
        int x2 = i * stepSize;
        int y2 = height() - (height() * ecgData[i]) / 100;

        painter.drawLine(x1, y1, x2, y2);
    }
}

void ECGWidget::updateECG() {
    // Repeat the existing ECG data
    ecgData.append(ecgData.first());
    ecgData.removeFirst();

    // Redraw the widget
    update();
}
