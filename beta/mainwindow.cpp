#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QGraphicsRectItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cont_I(0)
{
    ui->setupUi(this);
    this ->scene = new QGraphicsScene(this);
    this -> view = new QGraphicsView(this);

    scene -> setSceneRect(0,0,1080,720);
    view -> setScene(scene); //contiene todo lo que se va a interactuar en pantalla
    view -> resize(1080,720);
    Personaje = new QGraphicsRectItem(25,430,50,50);
    inventario = new QGraphicsRectItem(25,480,0, 0);

    scene-> addItem(Personaje);
    scene -> addItem(inventario);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    int move_x = 0;
    int move_y = 0;
    //movimiento del personaje
    switch (event -> key()) {
    case Qt::Key_W:
        move_y = -10;
        break;
    case Qt::Key_S:
        move_y = 10;
        break;
    case Qt::Key_D:
        move_x = 10;
        break;
    case Qt::Key_A:
        move_x = -10;
        break;
    //aparicion/desaparicion del inventario
    case Qt::Key_I:
        cont_I++;
        if(cont_I%2 == 0){
            inventario -> setRect(25,480, 0,0);
        }
        else{
            inventario -> setRect(25, 480, 750, 100);
        }
        break;
    default:
        break;
    }

    QPointF rectPosc = Personaje->pos(); // obtiene la posicion del rectangulo
    Personaje -> setPos(rectPosc.x()+ move_x, rectPosc.y()+move_y);

    // recuadro de inventario/dialogo


}
