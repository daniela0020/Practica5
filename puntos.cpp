#include "puntos.h"

puntos::puntos(int px, int py)
{
    posx=px;
    posy=py;
}

QRectF puntos::boundingRect() const
{
    return QRectF(-posx,-posy,10,10);
}
void puntos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());


}

int puntos::getPosx() const
{
    return posx;
}

int puntos::getPosy() const
{
    return posy;
}
