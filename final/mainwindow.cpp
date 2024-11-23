#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QGraphicsRectItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cont_I(0)
{
    // ConfiguraciÃ³n inicial de la ventana
    setWindowTitle("Juego de Lisa - Â¿QuiÃ©n matÃ³ al Sr. Burns?");
    resize(800, 600);

    // Crear los botones para los niveles
    botonNivel1 = new QPushButton("Nivel 1: Escena del Crimen", this);
    botonNivel2 = new QPushButton("Nivel 2: Entrevista a Sospechosos", this);
    botonNivel3 = new QPushButton("Nivel 3: ResoluciÃ³n del Caso", this);

    // Conectar los botones a sus respectivos slots
    connect(botonNivel1, &QPushButton::clicked, this, &MainWindow::cambiarNivel1);
    connect(botonNivel2, &QPushButton::clicked, this, &MainWindow::cambiarNivel2);
    connect(botonNivel3, &QPushButton::clicked, this, &MainWindow::cambiarNivel3);

    // Crear la vista grÃ¡fica
    vista = new QGraphicsView(this);

    // Configurar el layout con botones y la vista
    layout = new QVBoxLayout;
    layout->addWidget(botonNivel1);
    layout->addWidget(botonNivel2);
    layout->addWidget(botonNivel3);
    layout->addWidget(vista);

    // Asignar el layout al widget central
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Iniciar el primer nivel
    cambiarNivel1();


    ui->setupUi(this);
    this ->scene = new QGraphicsScene(this);
    this -> vista = new QGraphicsView(this);

    scene -> setSceneRect(0,0,1080,720);
    vista -> setScene(scene); //contiene todo lo que se va a interactuar en pantalla
    vista -> resize(1080,720);
    Personaje = new QGraphicsRectItem(0,0,50,50);
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

void MainWindow::cambiarNivel1() {
    QGraphicsScene* escena = new QGraphicsScene();
    juego->cargarNivel(1);
    vista->setScene(escena); // Mostrar la escena del nivel 1 en la vista
}

void MainWindow::cambiarNivel2() {
    QGraphicsScene* escena = new QGraphicsScene();
    juego->cargarNivel(2);
    vista->setScene(escena); // Mostrar la escena del nivel 2 en la vista
}

void MainWindow::cambiarNivel3() {
    QGraphicsScene* escena = new QGraphicsScene();
    juego->cargarNivel(3);
    vista->setScene(escena); // Mostrar la escena del nivel 3 en la vista
}
