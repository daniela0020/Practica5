#ifndef PUNTOS_H
#define PUNTOS_H
#include <QPainter>
#include <QGraphicsItem>

class puntos : public QGraphicsItem
{
    int posx;
    int posy;
    int r;
public:
    puntos(int px, int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getPosx() const;
    int getPosy() const;
};

#endif // PUNTOS_H
