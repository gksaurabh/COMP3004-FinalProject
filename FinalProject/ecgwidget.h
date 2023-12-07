#ifndef ECGWIDGET_H
#define ECGWIDGET_H

#include <QWidget>

class QTimer;

class ECGWidget : public QWidget {


public:
    ECGWidget(QWidget *parent = nullptr);
    void setECGData(const QList<int> &data);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateECG();

private:
    QTimer *timer;
    QList<int> ecgData;
};

#endif // ECGWIDGET_H
