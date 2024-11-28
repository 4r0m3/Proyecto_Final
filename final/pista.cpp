#include "Pista.h"
#include <iostream>
#include <QPainter>

// Constructor
Pista::Pista(const string& descripcion, bool esClave)
    : ObjetoInteractivo("Pista"), descripcion(descripcion), esClave(esClave) {}

// Maneja la interacción con la pista
void Pista::interactuar() {
    std::cout << "Pista inspeccionada: " << descripcion << std::endl;
    if (esClave) {
        std::cout << "Esta pista es clave para el caso." << std::endl;
    }
}

// Devuelve la descripción de la pista
string Pista::obtenerDescripcion() const {
    return descripcion;
}

// Marca la pista como clave
void Pista::marcarComoClave() {
    esClave = true;
}

// Define el área del objeto en la escena
QRectF Pista::boundingRect() const {
    return QRectF(0, 0, 50, 50); // Área rectangular de 50x50 píxeles
}

// Dibuja el objeto en la escena
void Pista::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(Qt::yellow); // Color amarillo para las pistas
    painter->drawRect(boundingRect()); // Dibuja un rectángulo
}

