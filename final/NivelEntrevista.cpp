#include "NivelEntrevista.h"
#include "Lisa.h"
#include <iostream>

NivelEntrevista::NivelEntrevista(Inventario* inventario) : Nivel(inventario) {}

void NivelEntrevista::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    objetivo = "Interroga a los sospechosos basándote en las pistas.";
    std::cout << "Objetivo del nivel: " << objetivo << std::endl;

    // Agregar los sospechosos a la escena
    for (auto* sospechoso : sospechosos) {
        escena->addItem(sospechoso);
    }
}

void NivelEntrevista::terminarNivel() {
    std::cout << "Nivel de entrevistas completado." << std::endl;
    // Aquí podrías emitir una señal para avanzar al siguiente nivel o regresar al menú
}

void NivelEntrevista::agregarSospechoso(Sospechoso* sospechoso) {
    sospechosos.push_back(sospechoso);
    if (escena) {
        escena->addItem(sospechoso);
    }
    std::cout << "Sospechoso agregado: " << sospechoso->getNombre() << std::endl;
}

void NivelEntrevista::mostrarSospechosos() const {
    std::cout << "Sospechosos en el nivel:" << std::endl;
    for (const auto* sospechoso : sospechosos) {
        std::cout << "- " << sospechoso->getNombre() << std::endl;
    }
}

void NivelEntrevista::actualizar() {
    // Verificar si se interactuó con todos los sospechosos
    bool nivelCompletado = true;
    for (auto* sospechoso : sospechosos) {
        if (!sospechoso->haSidoEntrevistado()) {
            nivelCompletado = false;
            break;
        }
    }

    if (nivelCompletado) {
        std::cout << "¡Has entrevistado a todos los sospechosos!" << std::endl;
        terminarNivel();
    }
}

