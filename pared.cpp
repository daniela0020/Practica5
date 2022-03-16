#include "pared.h"

Pared::Pared()
{

}
int Pared::getPosx() const
{
    return posx;
}

int Pared::getPosy() const
{
    return posy;
}
Pared::Pared(int w, int h, int px, int py)
{
    ancho=w;
    alto=h;
    posx=px;
    posy=py;
}

QRectF Pared::boundingRect() const
{
    return QRectF(-posx,-posy,ancho,alto);
}

void Pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}


