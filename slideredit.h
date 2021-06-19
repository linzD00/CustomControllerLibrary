#ifndef SLIDEREDIT_H
#define SLIDEREDIT_H

#include <QLineEdit>
#include <QObject>
#include <QWidget>
#include <Qt3DInput/QMouseEvent>

class SliderEdit : public QLineEdit{
    Q_OBJECT
private:
    QPointF pressedPos;

    bool _isRightPressed = false;
    double _moveStep = 1.00;//鼠标长按移动步长

protected:
    virtual void mousePressEvent(QMouseEvent * eve);
    virtual void mouseMoveEvent(QMouseEvent * eve);
    virtual void mouseReleaseEvent(QMouseEvent * eve);

public:
     SliderEdit(QWidget *parent = nullptr);
    ~SliderEdit();
    void SetMoveStep(double step);//设置鼠标长按移动步长

Q_SIGNALS:
    void sig_valueDragged();

};

#endif // SLIDEREDIT_H
