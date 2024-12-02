#include "Juego.h"
#include "NivelEscenaCrimen.h"
#include "NivelEntrevista.h"
#include "NivelResolucion.h"
#include <iostream>
#include <QGraphicsView>

// Constructor de la clase Juego
juego::juego() : inventario(new Inventario()), nivelActual(nullptr), nivelActualID(0), vista(nullptr), pistasRecolectadas(0), sospechososEntrevistados(0) {}

// Destructor de la clase Juego
juego::~juego() {
    delete inventario;
    delete nivelActual;
}

// Inicia el juego desde el primer nivel
void juego::iniciarJuego(QGraphicsView* vista) {
    this->vista = vista; // Asocia la vista para centrarla en Lisa
    std::cout << "Bienvenido al juego." << std::endl;
    cargarNivel(1); // Inicia con el primer nivel
}

// Carga el nivel especificado y libera el anterior
void juego::cargarNivel(int nivelID) {
    delete nivelActual; // Limpia el nivel anterior

    switch (nivelID) {
    case 1:
        nivelActual = new NivelEscenaCrimen(inventario, this);  // Pasamos inventario y el puntero a juego
        pistasRecolectadas = 0; // Reinicia las pistas recolectadas
        std::cout << "Nivel 1: Escena del crimen cargado." << std::endl;
        break;
    case 2:
        if (nivelCompletado(1)) {
            nivelActual = new NivelEntrevista(inventario, this);  // Asegúrate de pasar el puntero a juego
            sospechososEntrevistados = 0;
            std::cout << "Nivel 2: Entrevista a sospechosos cargado." << std::endl;
        } else {
            std::cout << "Debes completar el Nivel 1 primero." << std::endl;
            return;
        }
        break;
    case 3:
        if (nivelCompletado(2)) {
            nivelActual = new NivelResolucion(inventario, this);  // Asegúrate de pasar el puntero a juego
            std::cout << "Nivel 3: Resolución del caso cargado." << std::endl;
        } else {
            std::cout << "Debes completar el Nivel 2 primero." << std::endl;
            return;
        }
        break;
    default:
        nivelActual = nullptr;
        std::cout << "Error: Nivel no válido." << std::endl;
        return;
    }

    nivelActualID = nivelID;
    if (nivelActual) {
        QGraphicsScene* escena = new QGraphicsScene();
        nivelActual->iniciarNivel(escena); // Inicia el nivel con la escena gráfica
        vista->setScene(escena);           // Asocia la escena a la vista
        centrarVistaEnLisa();
    }
}

// Método para centrar la vista en Lisa
void juego::centrarVistaEnLisa() const {
    if (nivelActual && vista) {
        class Lisa* lisa = nivelActual->getLisa(); // Obtén a Lisa del nivel actual
        if (lisa) {
            vista->centerOn(lisa); // Centra la vista en Lisa
        }
    }
}

// Método para registrar pistas recolectadas en el nivel 1
void juego::registrarPista() {
    pistasRecolectadas++;
    std::cout << "Pistas recolectadas: " << pistasRecolectadas << std::endl;
    if (pistasRecolectadas >= 5) { // Suponiendo que hay 5 pistas en el nivel 1
        std::cout << "¡Has recolectado todas las pistas! Nivel 1 completado." << std::endl;
    }
}

// Método para registrar sospechosos entrevistados en el nivel 2
void juego::registrarEntrevista() {
    sospechososEntrevistados++;
    std::cout << "Sospechosos entrevistados: " << sospechososEntrevistados << std::endl;
    if (sospechososEntrevistados >= 6) { // Suponiendo que hay 6 sospechosos
        std::cout << "¡Has entrevistado a todos los sospechosos! Nivel 2 completado." << std::endl;
    }
}

// Método para verificar si un nivel ha sido completado
bool juego::nivelCompletado(int nivelID) const {
    switch (nivelID) {
    case 1:
        return (pistasRecolectadas >= 5); // Nivel 1 se completa recolectando todas las pistas
    case 2:
        return (sospechososEntrevistados >= 6); // Nivel 2 se completa entrevistando a todos los sospechosos
    case 3:
        return (nivelActualID == 3); // Nivel 3 se completa con la revelación del caso
    default:
        return false;
    }
}

// Método que devuelve la escena del nivel actual
QGraphicsScene* juego::getEscenaActual() const {
    return nivelActual ? nivelActual->getEscena() : nullptr;
}

