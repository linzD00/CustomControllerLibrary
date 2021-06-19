#ifndef NOTELABELSLIDER_H
#define NOTELABELSLIDER_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <Qt3DInput/QMouseEvent>

class NotelabelSlider:public QSlider
{
    Q_OBJECT
public:
    NotelabelSlider(QWidget *parent = nullptr);
    ~NotelabelSlider();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    QLabel*	noteLabel;

};

#endif // NOTELABELSLIDER_H
