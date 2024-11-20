#include "NivelEscenaCrimen.h"
#include "Pista.h"
#include <iostream>

// Constructor
NivelEscenaCrimen::NivelEscenaCrimen(Inventario* inventario) : Nivel(inventario) {
    objetivo = "Recolectar todas las pistas en la escena del crimen.";
}

// Inicia el nivel
void NivelEscenaCrimen::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    cout << "Nivel Escena del Crimen iniciado." << endl;
    cout << "Objetivo: " << objetivo << endl;

    // Crear objetos interactivos a partir del mapa
    for (const auto& [id, descripcion] : objetosMapa) {
        Pista* pista = new Pista(descripcion, true);
        agregarObjetoInteractivo(pista);
    }
}

// Finaliza el nivel
void NivelEscenaCrimen::terminarNivel() {
    cout << "Nivel Escena del Crimen completado." << endl;
}

// Carga objetos interactivos desde un mapa
void NivelEscenaCrimen::cargarObjetos(const map<int, string>& objetos) {
    objetosMapa = objetos;
    cout << "Objetos cargados en la escena del crimen." << endl;
}
