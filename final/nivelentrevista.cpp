#include "NivelEntrevista.h"
#include <iostream>

// Constructor
NivelEntrevista::NivelEntrevista(Inventario* inventario) : Nivel(inventario) {
    objetivo = "Entrevistar a los sospechosos utilizando las pistas recolectadas.";
}

// Inicia el nivel
void NivelEntrevista::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    cout << "Nivel Entrevista a Sospechosos iniciado." << endl;
    cout << "Objetivo: " << objetivo << endl;

    // Agregar sospechosos a la escena
    for (auto* sospechoso : sospechosos) {
        agregarObjetoInteractivo(sospechoso);
    }
}

// Finaliza el nivel
void NivelEntrevista::terminarNivel() {
    cout << "Nivel Entrevista a Sospechosos completado." << endl;
}

// Agrega un sospechoso al nivel
void NivelEntrevista::agregarSospechoso(Sospechoso* sospechoso) {
    if (sospechoso) {
        sospechosos.push_back(sospechoso);
        cout << "Sospechoso agregado: " << sospechoso->obtenerNombre() << endl;
    }
}

// Muestra los sospechosos disponibles
void NivelEntrevista::mostrarSospechosos() const {
    cout << "Sospechosos disponibles para entrevista:" << endl;
    for (const auto& sospechoso : sospechosos) {
        cout << "- " << sospechoso->obtenerNombre() << endl;
    }
}

