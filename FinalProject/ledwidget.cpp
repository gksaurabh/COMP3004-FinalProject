#include "ledwidget.h"
#include <QPainter>

LedWidget::LedWidget(QWidget *parent)
    : QWidget(parent), ledColor(Qt::gray) {
    setFixedSize(20, 20); // Set your desired size for the LED
}

void LedWidget::setColor(const QColor& color) {
    ledColor = color;
    update(); // Trigger a repaint
}


void LedWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Draw the colored LED
    painter.setBrush(ledColor);
    painter.drawEllipse(rect());
}
