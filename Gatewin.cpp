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
    *@Title:001 SliderLineEdit ���������
    *********/
    //SliderEdit * mSlidereditor = new SliderEdit();
    //mGatelayout->addWidget(mSlidereditor);
    
    /*********
    *@Author: Linz;
    *@Time:
    *@Title:002 NoteSlider ��ǩ������
    *********/
    //NotelabelSlider * mNoteSlider = new NotelabelSlider();
    //mGatelayout->addWidget(mNoteSlider);


    /*********
    *@Author: Linz;
    *@Time:2021/06/19
    *@Title:003 Bubblemessage ������Ϣ��
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

// ��ʾ
void Gatewin::showMessage()
{
    QRect rect = QApplication::desktop()->availableGeometry();
    mpoint.setX(1920 - width());
    mpoint.setY(1080 - height());
    move(mpoint.x(), mpoint.y());
    m_pShowTimer->start(5);
}

// �ƶ�
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

// פ��
void Gatewin::onStay()
{
    m_pStayTimer->stop();
    m_pCloseTimer->start(100);
}

// �ر�
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
