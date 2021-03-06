#include "esfera.h"

void esfera::setPosy(int value)
{
    posy = value;
}

void esfera::setPosx(int value)
{
    posx = value;
}

int esfera::getPosx() const
{
    return posx;
}

int esfera::getPosy() const
{
    return posy;
}

esfera::esfera (int x)
{

}

esfera::esfera(int x, int y)
{
    timer =new QTimer();

    posx=x;

    posy=y;

    r=20;

    setPos(posx,posy);

    filas=0;

    columnas=0;

    pixmap=new QPixmap(":/Imagen/Pacman.png");

    timer->start(100); //modifica la velocidad en que itera entre las imagenes, tiempo en milisegundos

    connect(timer,&QTimer::timeout,this,&esfera::actualizacion);

}



QRectF esfera::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void esfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    //painter->setBrush(Qt::darkBlue);
    //painter->drawEllipse(boundingRect());
    //QPixmap pixmap;
    //pixmap.load(":/Imagen/Pacman.png");
    //painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
    painter->drawPixmap(-r,-r,*pixmap,columnas,filas,2*r,2*r);

}


void esfera::MoveRight()
{
    this->posx+=velocidad;
    filas=0;
    setPos(posx,posy);
}

void esfera::MoveLeft()
{
    this->posx-=velocidad;
    filas=39;
    setPos(posx,posy);
}

void esfera::MoveUp()
{
    this->posy-=velocidad;
    filas=78;
    setPos(posx,posy);
}

void esfera::MoveDown()
{
    this->posy+=velocidad;
    filas=117;
    setPos(posx,posy);
}

void esfera::actualizacion()
{
    columnas+=40;
    if(columnas>=190){
        columnas=0;
    }

    this->update(-r,-r,2*r,2*r);
}

/*

QRectF esfera::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void esfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());

    QPixmap pixmap;
    pixmap.load(":/../Pacman.png");

    painter->drawPixmap(-10,-10, *spriteImage, currentFrame, 0, 20,20);
}
void esfera::nextFrame()
{
    At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20

    currentFrame += 20;
    if (currentFrame >= 300 ) currentFrame = 0;
    this->update(-10,-10,20,20);
}
void esfera::mover()
{
    setPos(x(),y()+vy);
}

void esfera::choque()
{
    vy=-vy/1.3;
}
*/
