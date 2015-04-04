#include "linkfilter.h"

linkFilter::linkFilter(QObject *parent) :
    QObject(parent)
{
}

bool linkFilter::eventFilter(QObject * object, QEvent *event){
    if (event->type()==QEvent::WhatsThisClicked){
        QWhatsThisClickedEvent *wtcEvent = static_cast<QWhatsThisClickedEvent*>(event);
        emit linkClicked(wtcEvent->href());
        return true;
    }
    return false;
}
