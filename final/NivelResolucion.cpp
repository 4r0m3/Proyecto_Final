#include "NivelResolucion.h"
#include "Sospechoso.h"
#include "Lisa.h"
#include "Juego.h"
#include <iostream>
#include <QAbstractButton>
#include <QPushButton>
#include <QGraphicsView>

NivelResolucion::NivelResolucion(Inventario* inventario, juego* juego)
    : Nivel(inventario, juego) {}

void NivelResolucion::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;

    // Crear a Lisa
    Lisa* lisa = new Lisa(juego);
    escena->addItem(lisa);
    lisa->setPos(escena->width() / 2 - lisa->boundingRect().width() / 2, escena->height() / 2 - lisa->boundingRect().height() / 2);
    lisa->setZValue(1); // Asegúrate de que Lisa esté por encima de otros elementos

    // Crear al Sr. Burns
    QGraphicsTextItem* burns = new QGraphicsTextItem("Sr. Burns");
    burns->setPos(200, 500);
    escena->addItem(burns);

    // Crear el Dr. y los sospechosos
    Sospechoso* doctor = new Sospechoso("Dr. Hibbert", juego);
    doctor->setSprite(":/sprites/dr_hibbert.png");
    escena->addItem(doctor->getSprite());
    doctor->getSprite()->setPos(400, 200);
    doctor->setZValue(1);

    // Crear los botones de acusación
    crearBotonesAcusacion(escena);
}

void NivelResolucion::terminarNivel() {
    std::cout << "Nivel de resolución completado." << std::endl;
    // Aquí puedes emitir una señal o hacer algo más para finalizar el nivel
}

void NivelResolucion::actualizar() {
    // Aquí se puede verificar si Lisa ya ha interactuado con el Sr. Burns
    std::cout << "Nivel de resolución actualizado." << std::endl;
}

void NivelResolucion::crearBotonesAcusacion(QGraphicsScene* escena) {
    const QString sospechosos[6] = {"Barney", "Moe", "Marge", "Bart", "Skinner", "Smithers"};
    for (int i = 0; i < 6; i++) {
        botonSospechoso[i] = new QPushButton(sospechosos[i]);
        botonSospechoso[i]->setFixedSize(100, 50);
        botonSospechoso[i]->move(100 + (i * 150), 1000);  // Ubicación de los botones

        // Conectar la señal de click del botón al slot de acusar
        connect(botonSospechoso[i], SIGNAL(clicked()), this, SLOT(acusarSospechoso(i)));

        escena->addWidget(botonSospechoso[i]);
    }
}

void NivelResolucion::acusarSospechoso(int indice) {
    std::cout << "Lisa ha acusado a: " << botonSospechoso[indice]->text().toStdString() << std::endl;
    // Aquí el Dr. debería confirmar la acusación y hacer la interacción con el Sr. Burns
    textoMensaje = new QGraphicsTextItem("La verdadera culpable es Maggie Simpson.");
    textoMensaje->setPos(500, 300);
    escena->addItem(textoMensaje);
}
