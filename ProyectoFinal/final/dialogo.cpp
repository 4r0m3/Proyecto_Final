#include "dialogo.h"
#include <iostream>
using namespace std;


// Constructor por defecto
Dialogo::Dialogo() {}

// Agrega una respuesta correcta al mapa de respuestas
void Dialogo::agregarRespuestaCorrecta(int idPregunta, const string& respuesta) {
    respuestasCorrectas[idPregunta] = respuesta;
}

// Muestra todas las opciones de diÃ¡logo (se podrÃ­a personalizar mÃ¡s adelante)
void Dialogo::mostrarOpciones() const {
    cout << "Opciones de diÃ¡logo disponibles:" << endl;
    for (const auto& entry : respuestasCorrectas) {
        cout << "Pregunta ID " << entry.first << ": (oculta para jugador)" << endl;
    }
}

// Verifica si la respuesta del jugador es correcta
bool Dialogo::verificarRespuesta(int idPregunta, const string& respuestaJugador) const {
    try {
        // Lanza una excepciÃ³n si el ID de la pregunta no existe en el mapa
        if (respuestasCorrectas.at(idPregunta) == respuestaJugador) {
            return true;
        }
        return false;
    } catch (const out_of_range& e) {
        cerr << "Error: La pregunta con ID " << idPregunta << " no existe." << endl;
        throw; // Re-lanza la excepciÃ³n
    }
}
