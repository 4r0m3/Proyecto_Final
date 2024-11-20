#include "NivelResolucion.h"
#include <iostream>

// Constructor
NivelResolucion::NivelResolucion(Inventario* inventario) : Nivel(inventario), culpable("Maggie Simpson") {
    objetivo = "Utiliza las pistas y entrevistas para resolver el caso.";
}

// Inicia el nivel
void NivelResolucion::iniciarNivel(QGraphicsScene* escena) {
    this->escena = escena;
    cout << "Nivel ResoluciÃ³n del Caso iniciado." << endl;
    cout << "Objetivo: " << objetivo << endl;
}

// Finaliza el nivel
void NivelResolucion::terminarNivel() {
    cout << "Nivel ResoluciÃ³n del Caso completado." << endl;
}

// Resuelve el caso eligiendo al culpable
void NivelResolucion::resolverCaso(const string& sospechoso) {
    cout << "Has elegido como culpable a: " << sospechoso << endl;
    if (sospechoso == culpable) {
        cout << "Â¡Correcto! El culpable es: " << culpable << "." << endl;
    } else {
        cout << "No es correcto. El culpable real es: " << culpable << "." << endl;
    }
}
