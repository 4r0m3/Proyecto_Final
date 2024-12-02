#include "MainWindow.h"
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), juego(new class juego()) {
    // Configuración inicial de la ventana
    setWindowTitle("Juego de Lisa - ¿Quién mató al Sr. Burns?");
    resize(800, 600); // Tamaño inicial de la ventana

    // Crear la vista gráfica
    vista = new QGraphicsView(this);
    setCentralWidget(vista);

    // Crear la escena de menú con fondo
    escenaMenu = new QGraphicsScene(this);
    escenaMenu->setSceneRect(0, 0, 2400, 1800); // Tamaño de la escena grande
    escenaMenu->setBackgroundBrush(QBrush(QPixmap(":/sprites/menu.png"))); // Fondo de la escena

    QPushButton* botonIniciar = new QPushButton("Iniciar Juego");
    botonIniciar->setFixedSize(200, 50); // Tamaño del botón
    botonIniciar->move(300, 250); // Posición inicial dentro del área visible
    connect(botonIniciar, &QPushButton::clicked, this, &MainWindow::irSeleccionNiveles);
    escenaMenu->addWidget(botonIniciar);

    // Crear la escena de selección de niveles con fondo
    escenaSeleccionNiveles = new QGraphicsScene(this);
    escenaSeleccionNiveles->setSceneRect(0, 0, 2400, 1800);
    escenaSeleccionNiveles->setBackgroundBrush(QBrush(QPixmap(":/sprites/menu.png")));

    QPushButton* botonNivel1 = new QPushButton("Nivel 1: Escena del Crimen");
    QPushButton* botonNivel2 = new QPushButton("Nivel 2: Entrevista a Sospechosos");
    QPushButton* botonNivel3 = new QPushButton("Nivel 3: Resolución del Caso");

    botonNivel1->setFixedSize(200, 50);
    botonNivel2->setFixedSize(200, 50);
    botonNivel3->setFixedSize(200, 50);

    botonNivel1->move(100, 200); // Coordenadas visibles iniciales
    botonNivel2->move(400, 300);
    botonNivel3->move(100, 400);

    connect(botonNivel1, &QPushButton::clicked, this, &MainWindow::cambiarNivel1);
    connect(botonNivel2, &QPushButton::clicked, this, &MainWindow::cambiarNivel2);
    connect(botonNivel3, &QPushButton::clicked, this, &MainWindow::cambiarNivel3);

    escenaSeleccionNiveles->addWidget(botonNivel1);
    escenaSeleccionNiveles->addWidget(botonNivel2);
    escenaSeleccionNiveles->addWidget(botonNivel3);

    // Mostrar la escena del menú por defecto
    vista->setScene(escenaMenu);
    vista->setSceneRect(0, 0, 800, 600); // Configura el área visible inicial

    // Configuración de la vista
    vista->setRenderHint(QPainter::Antialiasing);
    vista->setRenderHint(QPainter::SmoothPixmapTransform);
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Desactivar barras de desplazamiento horizontal
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Desactivar barras de desplazamiento vertical
    vista->setResizeAnchor(QGraphicsView::AnchorViewCenter); // Mantener la vista centrada
}

MainWindow::~MainWindow() {
    delete juego;
    delete escenaMenu;
    delete escenaSeleccionNiveles;
}

void MainWindow::irSeleccionNiveles() {
    vista->setScene(escenaSeleccionNiveles);
}

void MainWindow::cambiarNivel1() {
    juego->cargarNivel(1);
    QGraphicsScene* escena = juego->getEscenaActual();
    escena->setSceneRect(0, 0, 2400, 1800); // Tamaño de la escena del nivel 1
    escena->setBackgroundBrush(QBrush(QPixmap(":/sprites/parqueadero.png")));

    // Ajustar la vista para mostrar toda la escena
    vista->setScene(escena);
    vista->setRenderHint(QPainter::Antialiasing);
    vista->setRenderHint(QPainter::SmoothPixmapTransform);
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // Activar barra de desplazamiento horizontal
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);   // Activar barra de desplazamiento vertical
}

void MainWindow::cambiarNivel2() {
    if (juego->nivelCompletado(1)) {
        juego->cargarNivel(2);
        QGraphicsScene* escena = juego->getEscenaActual();
        escena->setSceneRect(0, 0, 2400, 1800);
        escena->setBackgroundBrush(QBrush(QPixmap(":/sprites/pasillo00.png")));

        // Ajustar la vista para mostrar toda la escena
        vista->setScene(escena);
        vista->setRenderHint(QPainter::Antialiasing);
        vista->setRenderHint(QPainter::SmoothPixmapTransform);
        vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // Activar barra de desplazamiento horizontal
        vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);   // Activar barra de desplazamiento vertical
    } else {
        QMessageBox::warning(this, "Restricción", "Debes completar el Nivel 1 primero.");
    }
}

void MainWindow::cambiarNivel3() {
    if (juego->nivelCompletado(2)) {
        juego->cargarNivel(3);
        QGraphicsScene* escena = juego->getEscenaActual();
        escena->setSceneRect(0, 0, 2400, 1800);
        escena->setBackgroundBrush(QBrush(QPixmap(":/sprites/hospital.png")));

        // Ajustar la vista para mostrar toda la escena
        vista->setScene(escena);
        vista->setRenderHint(QPainter::Antialiasing);
        vista->setRenderHint(QPainter::SmoothPixmapTransform);
        vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // Activar barra de desplazamiento horizontal
        vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);   // Activar barra de desplazamiento vertical
    } else {
        QMessageBox::warning(this, "Restricción", "Debes completar el Nivel 2 primero.");
    }
}


