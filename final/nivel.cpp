#include "Nivel.h"
#include <iostream>

// Constructor
Nivel::Nivel(Inventario* inventario, juego* juego)
    : escena(nullptr), inventario(inventario) {}

// Destructor
Nivel::~Nivel() {
    delete escena;
    for (auto* objeto : objetosInteractivos) {
        delete objeto;
    }
}

// Devuelve la escena actual del nivel
QGraphicsScene* Nivel::getEscena() const {
    return escena;
}

// Agrega un objeto interactivo al nivel
void Nivel::agregarObjetoInteractivo(ObjetoInteractivo* objeto) {
    if (escena) {
        objetosInteractivos.push_back(objeto);
        escena->addItem(objeto);
    }
}


