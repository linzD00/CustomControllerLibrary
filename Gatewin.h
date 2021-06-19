#ifndef GATEWIN_H
#define GATEWIN_H

#include <QWidget>

class SliderEdit;
class Gatewin:public QWidget
{
    Q_OBJECT
private:
    QTimer * m_pShowTimer;
    QTimer * m_pStayTimer;
    QTimer * m_pCloseTimer;

    double m_dTransparent = 1.0;
    double mDesktopHeight;
    QPoint mpoint;

public:
    Gatewin();
    ~Gatewin();

    void showMessage();

    void onMove();

    void onStay();

    void onClose();

};

#endif // GATEWIN_H
