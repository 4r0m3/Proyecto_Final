#include "Pista.h"
#include <iostream>
#include <QPainter>

// Constructor
Pista::Pista(const QString& descripcion, bool esClave)
    : ObjetoInteractivo("Pista"), descripcion(descripcion.toStdString()), Clave(esClave), interactuado(false) {}

bool Pista::esClave() const {
    return Clave; // Retorna el valor de la pista clave
}

// Maneja la interacción con la pista
void Pista::interactuar() {
    if (!interactuado) {
        std::cout << "Pista recogida: " << descripcion << std::endl;
        interactuado = true; // Marca la pista como interactuada
        if (Clave) {
            std::cout << "Esta pista es clave para el caso." << std::endl;
        }
    } else {
        std::cout << "Esta pista ya fue recogida." << std::endl;
    }
}

// Devuelve la descripción de la pista
string Pista::obtenerDescripcion() const {
    return descripcion;
}

// Marca la pista como clave
void Pista::marcarComoClave() {
    Clave = true;
}

// Verifica si la pista ya fue interactuada
bool Pista::esInteractuado() const {
    return interactuado;
}

// Define el área del objeto en la escena
QRectF Pista::boundingRect() const {
    return QRectF(0, 0, 50, 50); // Área rectangular de 50x50 píxeles
}

// Dibuja el objeto en la escena
void Pista::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    if (!interactuado) {
        painter->setBrush(Qt::yellow); // Color amarillo para las pistas no recogidas
    } else {
        painter->setBrush(Qt::gray);   // Color gris para las pistas ya recogidas
    }
    painter->drawRect(boundingRect()); // Dibuja un rectángulo
}
