#ifndef PARED_H
#define PARED_H
#include<QGraphicsItem>
#include<QPainter>

class Pared : public QGraphicsItem
{
    int alto,ancho,posx,posy;
public:
    Pared();
    Pared(int w,int h, int px, int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() const;
    int getPosy() const;
};

#endif // PARED_H
