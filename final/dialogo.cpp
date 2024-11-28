#include "Dialogo.h"
#include "Sospechoso.h"
#include <iostream>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QFont>

using namespace std;

// Constructor por defecto
Dialogo::Dialogo() {}

// Agrega una respuesta correcta al mapa de respuestas
void Dialogo::agregarRespuestaCorrecta(int idPregunta, const string& respuesta) {
    respuestasCorrectas[idPregunta] = respuesta;
}

// Muestra todas las opciones de diálogo (se podría personalizar más adelante)
void Dialogo::mostrarOpciones() const {
    cout << "Opciones de diálogo disponibles:" << endl;
    for (const auto& entry : respuestasCorrectas) {
        cout << "Pregunta ID " << entry.first << ": (oculta para jugador)" << endl;
    }
}

// Verifica si la respuesta del jugador es correcta
bool Dialogo::verificarRespuesta(int idPregunta, const string& respuestaJugador) const {
    try {
        // Verifica si la respuesta es correcta
        if (respuestasCorrectas.at(idPregunta) == respuestaJugador) {
            return true;
        }
        return false;
    } catch (const out_of_range& e) {
        cerr << "Error: La pregunta con ID " << idPregunta << " no existe." << endl;
        throw; // Re-lanza la excepción
    }
}

// Inicia un diálogo con un sospechoso
void Dialogo::iniciarDialogo(Sospechoso* sospechoso, QGraphicsScene* escena) {
    if (sospechoso->haSidoEntrevistado()) {
        mostrarBurbuja("Ya has entrevistado a " + QString::fromStdString(sospechoso->obtenerNombre()), escena);
        return;
    }

    mostrarBurbuja("Entrevistando a " + QString::fromStdString(sospechoso->obtenerNombre()), escena);
    sospechoso->marcarEntrevistado();

    // Muestra preguntas relacionadas al sospechoso (simulación de interacción)
    for (const auto& [idPregunta, respuesta] : respuestasCorrectas) {
        mostrarBurbuja("Pregunta ID " + QString::number(idPregunta), escena);
    }
}

// Muestra una burbuja de diálogo en la parte baja de la pantalla
void Dialogo::mostrarBurbuja(const QString& texto, QGraphicsScene* escena) {
    QGraphicsRectItem* burbuja = new QGraphicsRectItem(0, 0, 400, 80);
    burbuja->setBrush(QBrush(Qt::white));
    burbuja->setPen(QPen(Qt::black));
    burbuja->setZValue(1); // Aparece por encima de otros elementos
    burbuja->setPos(50, escena->height() - 100); // Parte baja de la pantalla

    QGraphicsTextItem* textoItem = new QGraphicsTextItem(texto, burbuja);
    textoItem->setFont(QFont("Arial", 12));
    textoItem->setDefaultTextColor(Qt::black);
    textoItem->setPos(10, 10); // Margen interno

    escena->addItem(burbuja);

    // Elimina la burbuja después de 3 segundos
    QTimer::singleShot(3000, [=]() {
        escena->removeItem(burbuja);
        delete burbuja;
    });
}
