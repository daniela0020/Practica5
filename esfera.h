#ifndef ESFERA_H
#define ESFERA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>
#include <QPixmap>

class esfera : public QObject, public QGraphicsItem
{
    int posx;
    int posy;
    int r;
    int velocidad=4;
public:
    esfera(int x);
    esfera(int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    int filas=0, columnas=0;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();

    void setPosy(int value);

    void setPosx(int value);

    int getPosx() const;

    int getPosy() const;

public slots:
    void actualizacion();
};

#endif // ESFERA_H
