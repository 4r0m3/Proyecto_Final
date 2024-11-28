#include "NivelEscenaCrimen.h"
#include "Pista.h"
#include <iostream>

NivelEscenaCrimen::NivelEscenaCrimen(Inventario* inventario) : Nivel(inventario) {}

void NivelEscenaCrimen::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    objetivo = "Recolecta todas las pistas en la escena del crimen.";
    std::cout << "Objetivo del nivel: " << objetivo << std::endl;

    // Cargar objetos desde el mapa y añadirlos a la escena
    for (const auto& [id, descripcion] : objetosMapa) {
        auto* pista = new Pista(descripcion, false);
        objetosInteractivos.push_back(pista);
        escena->addItem(pista);
    }
}

void NivelEscenaCrimen::terminarNivel() {
    std::cout << "Nivel de la escena del crimen completado." << std::endl;
    // Aquí podrías emitir una señal o llamar a una función para regresar al menú
}

void NivelEscenaCrimen::cargarObjetos(const map<int, string>& objetos) {
    objetosMapa = objetos;
    std::cout << "Objetos cargados en el nivel." << std::endl;
}

void NivelEscenaCrimen::actualizar() {
    // Verifica si todos los objetos interactivos han sido recolectados
    bool nivelCompletado = true;
    for (auto* objeto : objetosInteractivos) {
        if (!objeto->esInteractuado()) {
            nivelCompletado = false;
            break;
        }
    }

    if (nivelCompletado) {
        std::cout << "¡Has recolectado todas las pistas!" << std::endl;
        terminarNivel();
    }
}

