#include "Juego.h"
#include "NivelEscenaCrimen.h"
#include "NivelEntrevista.h"
#include "NivelResolucion.h"
#include <iostream>

juego::juego() : inventario(new Inventario()), nivelActual(nullptr), nivelActualID(0) {}

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

    switch (nivelID) {
    case 1:
        nivelActual = new NivelEscenaCrimen(inventario);  // Pasamos el inventario al nivel
        cout << "Nivel 1: Escena del crimen cargado." << endl;
        break;
    case 2:
        if (nivelCompletado(1)) {  // Verificamos que el nivel anterior esté completado
            nivelActual = new NivelEntrevista(inventario);
            cout << "Nivel 2: Entrevista a sospechosos cargado." << endl;
        } else {
            cout << "Debes completar el Nivel 1 primero." << endl;
            return; // No podemos acceder al nivel 2 sin completar el nivel 1
        }
        break;
    case 3:
        if (nivelCompletado(2)) {  // Verificamos que el nivel anterior esté completado
            nivelActual = new NivelResolucion(inventario);
            cout << "Nivel 3: Resolución del caso cargado." << endl;
        } else {
            cout << "Debes completar el Nivel 2 primero." << endl;
            return; // No podemos acceder al nivel 3 sin completar el nivel 2
        }
        break;
    default:
        nivelActual = nullptr;
        cout << "Error: Nivel no válido." << endl;
        return;
    }

    nivelActualID = nivelID;
    if (nivelActual) {
        QGraphicsScene* escena = new QGraphicsScene();  // Creamos una nueva escena para cada nivel
        nivelActual->iniciarNivel(escena);  // Inicia el nivel con la escena gráfica
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

// Método que devuelve la escena del nivel actual
QGraphicsScene* juego::getEscenaActual() const {
    return nivelActual ? nivelActual->getEscena() : nullptr;  // Devuelve la escena del nivel actual
}

// Método para verificar si un nivel ha sido completado
bool juego::nivelCompletado(int nivelID) const {
    switch (nivelID) {
    case 1:
        return (nivelActualID >= 1);  // Si el nivel actual es 1 o mayor, el nivel 1 está completo
    case 2:
        return (nivelActualID >= 2);  // Si el nivel actual es 2 o mayor, el nivel 2 está completo
    case 3:
        return (nivelActualID >= 3);  // Si el nivel actual es 3 o mayor, el nivel 3 está completo
    default:
        return false;
    }
}
