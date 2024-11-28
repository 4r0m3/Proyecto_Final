#include "Sospechoso.h"
#include <iostream>
#include <QPainter>

// Constructor
Sospechoso::Sospechoso(const string& nombre)
    : ObjetoInteractivo(nombre), entrevistado(false) {}

// Maneja la interacción con el sospechoso
void Sospechoso::interactuar() {
    if (!entrevistado) {
        cout << "Entrevistando a: " << nombre << endl;
        marcarEntrevistado();
    } else {
        cout << nombre << " ya ha sido entrevistado." << endl;
    }
}

// Devuelve el nombre del sospechoso
string Sospechoso::obtenerNombre() const {
    return getNombre(); // Usa el método heredado de ObjetoInteractivo
}

// Agrega una respuesta posible
void Sospechoso::agregarRespuesta(int idPregunta, const string& respuesta) {
    respuestas[idPregunta] = respuesta;
}

// Obtiene la respuesta a una pregunta específica
string Sospechoso::obtenerRespuesta(int idPregunta) const {
    auto it = respuestas.find(idPregunta);
    if (it != respuestas.end()) {
        return it->second;
    }
    return "Respuesta no disponible.";
}

// Verifica si el sospechoso ya ha sido entrevistado
bool Sospechoso::haSidoEntrevistado() const {
    return entrevistado;
}

// Marca al sospechoso como entrevistado
void Sospechoso::marcarEntrevistado() {
    entrevistado = true;
}
