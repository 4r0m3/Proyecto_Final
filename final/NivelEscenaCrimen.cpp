#include "NivelEscenaCrimen.h"
#include "Pista.h"
#include <iostream>
#include <juego.h>

NivelEscenaCrimen::NivelEscenaCrimen(Inventario* inventario, class juego* juego)
    : Nivel(inventario,juego) {}  // Guarda el puntero a juego


void NivelEscenaCrimen::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    objetivo = "Recolecta todas las pistas en la escena del crimen.";
    std::cout << "Objetivo del nivel: " << objetivo << std::endl;

    // Crear a Lisa y agregarla a la escena
    Lisa* lisa = new Lisa(juego);  // Aquí se pasa el puntero a juego, no el valor
    escena->addItem(lisa);
    lisa->setPos(escena->width() / 2 - lisa->boundingRect().width() / 2,
                 escena->height() / 2 - lisa->boundingRect().height() / 2);  // Centrada en la pantalla
    lisa->setZValue(1); // Asegúrate de que Lisa esté por encima de otros elementos
    // Crear a Marge (Sospechoso) y agregarla a la escena
    Sospechoso* marge = new Sospechoso("Marge Simpson");
    marge->setSprite(":/sprites/marge.png");  // Se asegura que el sprite se cargue correctamente
    escena->addItem(marge->getSprite());
    marge->getSprite()->setPos(100, 200); // Posición de Marge en la escena
    marge->setZValue(1); // Asegúrate de que Marge esté por encima de otros elementos

    // Cargar objetos (pistas) desde el mapa y añadirlos a la escena
    for (const auto& [id, descripcion] : objetosMapa) {
        // Convierte std::string a QString
        Pista* pista = new Pista(QString::fromStdString(descripcion), false);  // Crear una nueva pista
        objetosInteractivos.push_back(pista);       // Agregarla a los objetos interactivos
        escena->addItem(pista);                     // Añadirla a la escena
        pista->setPos(rand() % 2000, rand() % 1600); // Posiciona las pistas aleatoriamente dentro del rango
        pista->setZValue(0);                        // Asegura que las pistas estén debajo de los personajes
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
    // Verifica si todos los objetos interactivos (pistas) han sido recolectados
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

