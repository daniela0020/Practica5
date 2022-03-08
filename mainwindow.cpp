#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,600,541);
    scene->setBackgroundBrush(Qt::black);
    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;

    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/../fondo.png")));

    timer=new QTimer();



    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(25);

    barra=new QGraphicsRectItem(-30,-10,60,20);
    scene->addItem(barra);
    barra->setPos(200,300);

    l1=new QGraphicsLineItem(0,0,500,0);
    l2=new QGraphicsLineItem(0,0,0,400);
    l3=new QGraphicsLineItem(500,0,500,400);
    l4=new QGraphicsLineItem(0,400,500,400);
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);

    Pacman = new esfera(300,310);
    scene->addItem(Pacman);

}
/*
void MainWindow::animar()
{
    if(moverIx1 && barra->x()>30)
    {
        bola->setPos(bola->x()-2,bola->y());
    }
    if(moverDx1)
    {
        bola->setPos(bola->x()+2,bola->y());
    }
    if(moverUy1)
    {
        bola->setPos(bola->x(),bola->y()-2);
    }
    if(moverDy1)
    {
        bola->setPos(bola->x(),bola->y()+2);
    }

    if(barra->collidesWithItem(l2) || barra->collidesWithItem(l3))
    {
        moverIx1=false;
        if(bola->isVisible()){
            bola->hide();
            //delete bola;
        }

    }


    if(barra->collidesWithItem(bola))
    {
        if(bola->isVisible()){
            bola->hide();
            emit aviso(9);
            //delete bola;
        }

    }

    for(int i=0; i<bolas.length();i++)
    {
        bolas.at(i)->mover();
        if(!bolas.at(i)->collidingItems().empty())
        {
            bolas.at(i)->choque();
        }
    }
}
*/
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)

    {
        Pacman->MoveLeft();
        //moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        Pacman->MoveRight();
        //moverDx1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        Pacman->MoveUp();
        //moverUy1=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        Pacman->MoveDown();
        //moverDy1=true;
    }
    /*else if(ev->key()==Qt::Key_X)
    {
        delete bola;
    }*/
}
/*
void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=false;
    }
}

void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}
*/
MainWindow::~MainWindow()
{
    //delete scene;
    delete ui;
}

