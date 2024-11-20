#include "Pista.h"
#include <iostream>
#include <QPainter>

// Constructor
Pista::Pista(const string& descripcion, bool esClave)
    : ObjetoInteractivo("Pista"), descripcion(descripcion), esClave(esClave) {}

// Maneja la interacciÃ³n con la pista
void Pista::interactuar() {
    std::cout << "Pista inspeccionada: " << descripcion << std::endl;
    if (esClave) {
        std::cout << "Esta pista es clave para el caso." << std::endl;
    }
}

// Devuelve la descripciÃ³n de la pista
string Pista::obtenerDescripcion() const {
    return descripcion;
}

// Marca la pista como clave
void Pista::marcarComoClave() {
    esClave = true;
}

// Define el Ã¡rea del objeto en la escena
QRectF Pista::boundingRect() const {
    return QRectF(0, 0, 50, 50); // Ãrea rectangular de 50x50 pÃ­xeles
}

// Dibuja el objeto en la escena
void Pista::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(Qt::yellow); // Color amarillo para las pistas
    painter->drawRect(boundingRect()); // Dibuja un rectÃ¡ngulo
}
