#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QDebug>
#include <QRectF>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>
#include <list>
#include <QPixmap>
#include "esfera.h"
#include "pared.h"
#include "puntos.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ifstream lector;

signals:
    void aviso(int);

public slots:
    void aumentarPunt();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    list<Pared*> paredes;
    list<puntos*> Puntos;
    esfera* Pacman;
    QTimer *timer;
    puntos* rectangulos;

    int puntuacion;

    int x,y,ancho,alto;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;

    void keyPressEvent(QKeyEvent *ev);
    void lecturaPosicionMuros();
    void lecturaPosicionPuntos();
    bool evaluarPacmanColisionMuro(list<Pared*>::iterator &ite);
    bool evaluarPacmanColisionPuntos(list<puntos*>::iterator &ite);
    int conversionStr2Int(string numero);
    void evaluarPacmanEnMapa(list<Pared*>::iterator &it);
    //void keyReleaseEvent(QKeyEvent *ev);
};
#endif // MAINWINDOW_H
