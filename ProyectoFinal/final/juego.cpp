#include "juego.h"
#include "NivelEscenaCrimen.h"
#include "NivelEntrevista.h"
#include "NivelResolucion.h"
#include <iostream>

// Constructor de la clase Juego
Juego::Juego() : inventario(new Inventario()), nivelActual(nullptr), puntosVerdad(0), nivelActualID(0) {}

// Destructor de la clase Juego
Juego::~Juego() {
    delete inventario;
    delete nivelActual;
}

// Inicia el juego desde el primer nivel
void Juego::iniciarJuego() {
    cout << "Bienvenido al juego." << endl;
    cargarNivel(1); // Inicia con el primer nivel
}

// Carga el nivel especificado y libera el anterior
void Juego::cargarNivel(int nivelID) {
    delete nivelActual; // Limpia el nivel anterior

    switch (nivelID) {
    case 1:
        //nivelActual = new NivelEscenaCrimen();
        cout << "Nivel 1: Escena del crimen cargado." << endl;
        break;
    case 2:
        nivelActual = new NivelEntrevista();
        cout << "Nivel 2: Entrevista a sospechosos cargado." << endl;
        break;
    case 3:
        nivelActual = new NivelResolucion();
        cout << "Nivel 3: ResoluciÃ³n del caso cargado." << endl;
        break;
    default:
        nivelActual = nullptr;
        cout << "Error: Nivel no vÃ¡lido." << endl;
        return;
    }

    nivelActualID = nivelID;
    if (nivelActual) nivelActual->iniciarNivel();
}

// Muestra el inventario actual llamando a Inventario::mostrarInventario
void Juego::mostrarInventario() const {
    inventario->mostrarInventario();
}

// Actualiza los puntos de verdad acumulados
void Juego::actualizarPuntosVerdad(int puntos) {
    puntosVerdad += puntos;
    cout << "Puntos de verdad actualizados a: " << puntosVerdad << endl;
}

// Retorna un puntero al inventario actual del juego
Inventario* Juego::getInventario() const {
    return inventario;
}
