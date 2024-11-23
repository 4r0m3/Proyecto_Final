#include "Juego.h"
#include "NivelEscenaCrimen.h"
#include "NivelEntrevista.h"
#include "NivelResolucion.h"
#include <iostream>

// Constructor de la clase Juego
juego::juego() : inventario(new Inventario()), nivelActual(nullptr), puntosVerdad(0), nivelActualID(0) {}

// Destructor de la clase Juego
juego::~juego() {
    delete inventario;
    delete nivelActual;
}

// Inicia el juego desde el primer nivel
void juego::iniciarJuego() {
    cout << "Bienvenido al juego." << endl;
    cargarNivel(1); // Inicia con el primer nivel
}

// Carga el nivel especificado y libera el anterior
void juego::cargarNivel(int nivelID) {
    delete nivelActual; // Limpia el nivel anterior

    QGraphicsScene* escena = new QGraphicsScene(); // Creamos una nueva escena para cada nivel

    switch (nivelID) {
    case 1:
        nivelActual = new NivelEscenaCrimen(inventario);  // Pasamos el inventario al nivel
        cout << "Nivel 1: Escena del crimen cargado." << endl;
        break;
    case 2:
        nivelActual = new NivelEntrevista(inventario);  // Pasamos el inventario al nivel
        cout << "Nivel 2: Entrevista a sospechosos cargado." << endl;
        break;
    case 3:
        nivelActual = new NivelResolucion(inventario);  // Pasamos el inventario al nivel
        cout << "Nivel 3: ResoluciÃ³n del caso cargado." << endl;
        break;
    default:
        nivelActual = nullptr;
        cout << "Error: Nivel no vÃ¡lido." << endl;
        return;
    }

    nivelActualID = nivelID;
    if (nivelActual) {
        nivelActual->iniciarNivel(escena); // Inicia el nivel con la escena grÃ¡fica
    }
}

// Muestra el inventario actual llamando a Inventario::mostrarInventario
void juego::mostrarInventario() const {
    inventario->mostrarInventario();
}

// Retorna un puntero al inventario actual del juego
Inventario* juego::getInventario() const {
    return inventario;
}
