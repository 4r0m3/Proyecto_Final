#include "NivelResolucion.h"
#include <iostream>

NivelResolucion::NivelResolucion(Inventario* inventario)
    : Nivel(inventario), culpable("Maggie Simpson") {}

void NivelResolucion::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    objetivo = "Resuelve el caso seleccionando al culpable.";
    std::cout << "Objetivo del nivel: " << objetivo << std::endl;

    // Configurar opciones de resolución (esto podría ser interactivo)
    // Ejemplo: Mostrar botones u objetos interactivos con los nombres de los sospechosos
}

void NivelResolucion::terminarNivel() {
    std::cout << "Nivel de resolución completado." << std::endl;
    // Aquí podrías finalizar el juego o regresar al menú principal
}

void NivelResolucion::resolverCaso(const string& sospechoso) {
    if (sospechoso == culpable) {
        std::cout << "¡Correcto! El culpable es Maggie Simpson." << std::endl;
    } else {
        std::cout << "Incorrecto. Intenta de nuevo." << std::endl;
    }
}

void NivelResolucion::actualizar() {
    // Aquí puedes agregar lógica para detectar la interacción con opciones de resolución
}
