#include "notelabelSlider.h"

NotelabelSlider::NotelabelSlider(QWidget * parent):
    QSlider(parent)
{
    setOrientation(Qt::Orientation::Horizontal);
    noteLabel=new QLabel(this);
    noteLabel->setFixedSize(QSize(20,20));
    noteLabel->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::white);
    noteLabel->setPalette(palette);
    noteLabel->setAlignment(Qt::AlignCenter);
    noteLabel->setVisible(false);
    noteLabel->move(0,3);
}

NotelabelSlider::~NotelabelSlider(){

}

void NotelabelSlider::mousePressEvent(QMouseEvent *event)
{
    if(!noteLabel->isVisible())
    {
        noteLabel->setVisible(true);
        noteLabel->setText(QString::number(this->value()));
    }
    QSlider::mousePressEvent(event);
}

void NotelabelSlider::mouseReleaseEvent(QMouseEvent *event)
{
    if(noteLabel->isVisible())
    {
        noteLabel->setVisible(false);
    }
    QSlider::mouseReleaseEvent(event);
}

void NotelabelSlider::mouseMoveEvent(QMouseEvent *event)
{
    noteLabel->setText(QString::number(this->value()));
    noteLabel->move((this->width()-noteLabel->width())*this->value()/(this->maximum()-this->minimum()),3);
    QSlider::mouseMoveEvent(event);
}
