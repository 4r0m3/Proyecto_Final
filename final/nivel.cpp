#include "Nivel.h"
#include <iostream>

// Constructor
Nivel::Nivel(Inventario* inventario) : inventario(inventario), escena(nullptr) {}

// Destructor
Nivel::~Nivel() {
    for (auto objeto : objetosInteractivos) {
        delete objeto;
    }
    delete escena;
}

// Agrega un objeto interactivo a la escena
void Nivel::agregarObjetoInteractivo(ObjetoInteractivo* objeto) {
    if (objeto) {
        objetosInteractivos.push_back(objeto);
        if (escena) {
            escena->addItem(objeto); // Agregar objeto a la escena grÃ¡fica
        }
        cout << "Objeto interactivo agregado: " << objeto->getNombre() << endl;
    }
}

// Muestra los objetos interactivos disponibles
void Nivel::mostrarObjetosInteractivos() const {
    cout << "Objetos interactivos en el nivel:" << endl;
    for (const auto& objeto : objetosInteractivos) {
        cout << "- " << objeto->getNombre() << endl;
    }
}
