#include "ObjetoInteractivo.h"
#include <QPainter>

// Constructor
ObjetoInteractivo::ObjetoInteractivo(const string& nombre) : nombre(nombre) {}

// Devuelve el nombre del objeto
string ObjetoInteractivo::getNombre() const {
    return nombre;
}

// Define el Ã¡rea de colisiÃ³n del objeto
QRectF ObjetoInteractivo::boundingRect() const {
    return QRectF(0, 0, 50, 50); // TamaÃ±o genÃ©rico del objeto
}

// MÃ©todo abstracto interactuar() se implementarÃ¡ en clases derivadas
