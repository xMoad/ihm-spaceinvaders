#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QSlider;
QT_END_NAMESPACE

class LCDRange : public QWidget
{
    Q_OBJECT

public:
    LCDRange(QWidget *parent = 0);
    LCDRange(const QString &text, QWidget *parent = 0);

    int value() const;
    QString text() const;

public slots:
    void setValue(int value);
    void setRange(int minValue, int maxValue);
    void setText(const QString &text);

signals:
    void valueChanged(int newValue);

private:
    void init();

    QSlider *slider;
    QLabel *label;
};

#endif
