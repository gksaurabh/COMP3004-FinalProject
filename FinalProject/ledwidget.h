#ifndef LEDWIDGET_H
#define LEDWIDGET_H

#include <QWidget>
#include <QColor>

class LedWidget : public QWidget {
    Q_OBJECT

public:
    explicit LedWidget(QWidget *parent = nullptr);
    void setColor(const QColor& color);
    void setSize(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QColor ledColor;
    LedWidget *ledLight;
};

#endif // LEDWIDGET_H
