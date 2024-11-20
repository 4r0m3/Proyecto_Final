#include "Sospechoso.h"
#include <iostream>
#include <QPainter>

// Constructor
Sospechoso::Sospechoso(const string& nombre)
    : ObjetoInteractivo(nombre) {}

// Maneja la interacciÃ³n con el sospechoso
void Sospechoso::interactuar() {
    cout << "InteracciÃ³n con el sospechoso: " << nombre << endl;
}

// Devuelve el nombre del sospechoso
string Sospechoso::obtenerNombre() const {
    return getNombre(); // Usa el mÃ©todo heredado de ObjetoInteractivo
}

// Agrega una respuesta posible
void Sospechoso::agregarRespuesta(int idPregunta, const string& respuesta) {
    respuestas[idPregunta] = respuesta;
}

// Obtiene la respuesta a una pregunta especÃ­fica
string Sospechoso::obtenerRespuesta(int idPregunta) const {
    auto it = respuestas.find(idPregunta);
    if (it != respuestas.end()) {
        return it->second;
    }
    return "Respuesta no disponible.";
}
