#include "Gatewin.h"
#include "slideredit.h"
#include "notelabelSlider.h"
#include <QtWidgets>

Gatewin::Gatewin():
    QWidget(nullptr)
{
    QFormLayout * mGatelayout = new QFormLayout();
    setLayout(mGatelayout);

    /*********
    *@Author: Linz;
    *@Time:
    *@Title:001 SliderLineEdit 滑动输入框
    *********/
    //SliderEdit * mSlidereditor = new SliderEdit();
    //mGatelayout->addWidget(mSlidereditor);
    
    /*********
    *@Author: Linz;
    *@Time:
    *@Title:002 NoteSlider 标签滑动条
    *********/
    //NotelabelSlider * mNoteSlider = new NotelabelSlider();
    //mGatelayout->addWidget(mNoteSlider);


    /*********
    *@Author: Linz;
    *@Time:2021/06/19
    *@Title:003 Bubblemessage 气泡消息窗
    *********/
    //setFixedSize(900,600);
    //mDesktopHeight = height();

    //m_pShowTimer = new QTimer(this);
    //m_pStayTimer = new QTimer(this);
    //m_pCloseTimer = new QTimer(this);

    //connect(m_pShowTimer, &QTimer::timeout, this, &Gatewin::onMove);
    //connect(m_pStayTimer, &QTimer::timeout, this, &Gatewin::onStay);
    //connect(m_pCloseTimer, &QTimer::timeout, this, &Gatewin::onClose);

    //showMessage();

    /*********
    *@Author: Linz;
    *@Time:
    *@Title:004 
    *********/
}

Gatewin::~Gatewin()
{

}

// 显示
void Gatewin::showMessage()
{
    QRect rect = QApplication::desktop()->availableGeometry();
    mpoint.setX(1920 - width());
    mpoint.setY(1080 - height());
    move(mpoint.x(), mpoint.y());
    m_pShowTimer->start(5);
}

// 移动
void Gatewin::onMove()
{
    mDesktopHeight--;
    move(mpoint.x(), mDesktopHeight);
    if (mDesktopHeight <= mpoint.y())
    {
        m_pShowTimer->stop();
        m_pStayTimer->start(5000);
    }
}

// 驻留
void Gatewin::onStay()
{
    m_pStayTimer->stop();
    m_pCloseTimer->start(100);
}

// 关闭
void Gatewin::onClose()
{
    m_dTransparent -= 0.1;
    if (m_dTransparent <= 0.0)
    {
        m_pCloseTimer->stop();
        close();
    }
    else
    {
        setWindowOpacity(m_dTransparent);
    }
}
