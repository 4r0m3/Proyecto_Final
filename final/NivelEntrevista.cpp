#include "NivelEntrevista.h"
#include <juego.h>
#include "Sospechoso.h"
#include "Lisa.h"
#include <iostream>

NivelEntrevista::NivelEntrevista(Inventario* inventario, class juego* juego)
    : Nivel(inventario, juego) {} // Llamamos al constructor base con los dos parámetros
    // Aquí va el resto de la inicialización del nivel


void NivelEntrevista::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    objetivo = "Entrevista a los sospechosos. Obtén respuestas clave para resolver el caso.";
    std::cout << "Objetivo del nivel: " << objetivo << std::endl;

    // Crear a Lisa (asegúrate de pasar el puntero 'juego')
    Lisa* lisa = new Lisa(juego);
    escena->addItem(lisa);
    lisa->setPos(escena->width() / 2 - lisa->boundingRect().width() / 2,
                 escena->height() / 2 - lisa->boundingRect().height() / 2);
    lisa->setZValue(1);  // Asegurarse de que Lisa esté por encima de otros elementos

    // Crear y agregar sospechosos
    Sospechoso* barney = new Sospechoso("Barney Gumble");
    barney->setSprite(":/sprites/barney.png");
    escena->addItem(barney);
    barney->setZValue(1); // Asegúrate de que Barney esté por encima de otros elementos
    barney->setPos(100, 200); // Posicionar a Barney

    Sospechoso* moe = new Sospechoso("Moe Szyslak");
    moe->setSprite(":/sprites/moe.png");
    escena->addItem(moe);
    moe->setZValue(1);  // Asegúrate de que Moe esté por encima de otros elementos
    moe->setPos(400, 200); // Posicionar a Moe

    Sospechoso* marge = new Sospechoso("Marge Simpson");
    marge->setSprite(":/sprites/marge.png");
    escena->addItem(marge);
    marge->setZValue(1); // Asegúrate de que Marge esté por encima de otros elementos
    marge->setPos(700, 200); // Posicionar a Marge

    Sospechoso* bart = new Sospechoso("Bart Simpson");
    bart->setSprite(":/sprites/bart.png");
    escena->addItem(bart);
    bart->setZValue(1);  // Asegúrate de que Bart esté por encima de otros elementos
    bart->setPos(1000, 200); // Posicionar a Bart

    Sospechoso* skinner = new Sospechoso("Principal Skinner");
    skinner->setSprite(":/sprites/skinner.png");
    escena->addItem(skinner);
    skinner->setZValue(1);  // Asegúrate de que Skinner esté por encima de otros elementos
    skinner->setPos(1300, 200); // Posicionar a Skinner

    Sospechoso* smithers = new Sospechoso("Waylon Smithers");
    smithers->setSprite(":/sprites/smithers.png");
    escena->addItem(smithers);
    smithers->setZValue(1);  // Asegúrate de que Smithers esté por encima de otros elementos
    smithers->setPos(1600, 200); // Posicionar a Smithers

    // Agregar a todos los sospechosos a la lista
    agregarSospechoso(barney);
    agregarSospechoso(moe);
    agregarSospechoso(marge);
    agregarSospechoso(bart);
    agregarSospechoso(skinner);
    agregarSospechoso(smithers);
}


void NivelEntrevista::terminarNivel() {
    std::cout << "Nivel de la entrevista completado." << std::endl;
    // Lógica de transición al siguiente nivel
}

void NivelEntrevista::agregarSospechoso(Sospechoso* sospechoso) {
    sospechosos.push_back(sospechoso);
}

void NivelEntrevista::mostrarSospechosos() const {
    std::cout << "Sospechosos en este nivel: " << std::endl;
    for (const auto& sospechoso : sospechosos) {
        std::cout << "- " << sospechoso->obtenerNombre() << std::endl;  // Eliminar toStdString()
    }
}


void NivelEntrevista::actualizar() {
    // Verificar si todos los sospechosos han sido entrevistados
    bool entrevistasCompletadas = true;
    for (auto* sospechoso : sospechosos) {
        if (!sospechoso->haSidoEntrevistado()) {
            entrevistasCompletadas = false;
            break;
        }
    }

    if (entrevistasCompletadas) {
        std::cout << "¡Has entrevistado a todos los sospechosos!" << std::endl;
        terminarNivel();
    }
}
