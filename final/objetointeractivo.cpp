#include "ObjetoInteractivo.h"
#include <QPainter>

// Constructor
ObjetoInteractivo::ObjetoInteractivo(const string& nombre) : nombre(nombre), interactuado(false) {}

// Devuelve el nombre del objeto
string ObjetoInteractivo::getNombre() const {
    return nombre;
}

// Define el área de colisión del objeto
QRectF ObjetoInteractivo::boundingRect() const {
    return QRectF(0, 0, 50, 50); // Tamaño genérico del objeto
}

// Verifica si el objeto ya fue interactuado
bool ObjetoInteractivo::esInteractuado() const {
    return interactuado;
}

// Marca al objeto como interactuado
void ObjetoInteractivo::marcarInteractuado() {
    interactuado = true;
}
