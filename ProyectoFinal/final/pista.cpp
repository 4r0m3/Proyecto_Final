#include "Pista.h"

Pista::Pista(const std::string& descripcion) : descripcion(descripcion), clave(false) {}

void Pista::marcarComoClave() {
    clave = true;
}

bool Pista::esClave() const {
    return clave;
}
