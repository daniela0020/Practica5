#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QRect Desktop = QApplication::desktop()->screenGeometry();
    //x = Desktop.x();
    //y = Desktop.y();
    //ancho = Desktop.width()-100;
    //alto = Desktop.height()-100;
    scene=new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,708,790);
    scene->setBackgroundBrush(Qt::black);
    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;

    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/../fondo.png")));

    timer=new QTimer();

    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(25);

    Pacman = new esfera(25,755);
    scene->addItem(Pacman);

    lecturaPosicionMuros();
    lecturaPosicionPuntos();

}
void MainWindow::lecturaPosicionMuros()
{
    lector.open("PosParedes.txt");
    string leido;
    int posicion[4],contador=0;
    if(!lector.fail()){
        while(!lector.eof()){
            lector>>leido;
            posicion[contador]=conversionStr2Int(leido);
            contador++;
            if(contador==4){
                paredes.push_back(new Pared(posicion[0],posicion[1],posicion[2],posicion[3]));
                scene->addItem(paredes.back());
                posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                contador=0;

            }

        }
    }
    lector.close();

}

void MainWindow::lecturaPosicionPuntos()
{
    lector.open("PosPuntos.txt");
    string leido;
    int posicion[2],contador=0;
    if(!lector.fail()){
        while(!lector.eof()){
            lector>>leido;
            posicion[contador]=conversionStr2Int(leido);
            contador++;
            if(contador==2){
                Puntos.push_back(new puntos(posicion[0],posicion[1]));
                scene->addItem(Puntos.back());
                posicion[0]=0;posicion[1]=0;
                contador=0;

            }

        }
    }
    lector.close();

}

int MainWindow::conversionStr2Int(string numero)
{
    int multi=1,char2int=0;

    if(numero.at(0)=='-'){
        string numero2;
        for(int i=0;i<numero.size()-1;++i)
        {
            multi*=10;
            if(i!=0)numero2+=numero.at(i);
        }
       multi/=10;
       for(int i=0;i<numero2.size();++i){
          char2int+=(numero2.at(i)-48)*multi;
          multi/=10;
          }
       char2int*=-1;
    }
    else{
        for(int i=0;i<numero.size()-1;++i)
        {
            multi*=10;
        }
        for(int i=0;i<numero.size();++i){
        char2int+=(numero.at(i)-48)*multi;
        multi/=10;
        }
    }
    return char2int;
}
bool MainWindow::evaluarPacmanColisionMuro(list<Pared*>::iterator &ite)
{

    bool colision=false;

    for(ite=paredes.begin();ite!=paredes.end();ite++){
        if(Pacman->collidesWithItem(*ite)){
             colision=true;
            break;
        }
    }
    return colision;
}

bool MainWindow::evaluarPacmanColisionPuntos(list<puntos*>::iterator &ite)
{

    bool colision=false;

    for(ite=Puntos.begin();ite!=Puntos.end();ite++){
        if(Pacman->collidesWithItem(*ite)){
             colision=true;
            break;
        }
    }
    return colision;
}


void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    list<Pared*>::iterator it=paredes.begin();
    list<puntos*>::iterator itp=Puntos.begin();

    if(ev->key()==Qt::Key_A)

    {
        Pacman->MoveLeft();
        if(evaluarPacmanColisionMuro(it)){
            Pacman->MoveRight();
        }
        if (evaluarPacmanColisionPuntos(itp)){
            scene->removeItem(*itp);
            Puntos.erase(itp);
            emit aviso(9);
        }
        if(Pacman->getPosx()<= 0){
            Pacman->setPosx(649);
            Pacman->setPosy(387);
        }
        //moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        Pacman->MoveRight();
        if(evaluarPacmanColisionMuro(it)){
            Pacman->MoveLeft();
        }
        if (evaluarPacmanColisionPuntos(itp)){
            scene->removeItem(*itp);
            emit aviso(9);
        }
        if(Pacman->getPosx()>=700){
            Pacman->setPosx(50);
            Pacman->setPosy(387);
        }
        //moverDx1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        Pacman->MoveUp();
        if(evaluarPacmanColisionMuro(it)){
            Pacman->MoveDown();
        }
        if (evaluarPacmanColisionPuntos(itp)){
            scene->removeItem(*itp);
            Puntos.erase(itp);
            emit aviso(9);
        }
        //moverUy1=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        Pacman->MoveDown();
        if(evaluarPacmanColisionMuro(it)){
            Pacman->MoveUp();
        }
        if (evaluarPacmanColisionPuntos(itp)){
            scene->removeItem(*itp);
            Puntos.erase(itp);
            emit aviso(9);
        }
        //moverDy1=true;
    }
}
void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
}

MainWindow::~MainWindow()
{
    //delete scene;
    delete ui;
}

