#include "Inventario.h"
#include <iostream>

using namespace std;

// Constructor por defecto
Inventario::Inventario() {}

// Agrega una pista al inventario
void Inventario::agregarPista(Pista* pista) {
    if (pista && !pista->esInteractuado()) {
        pistas.push_back(pista);
        pista->interactuar(); // Marca la pista como interactuada
        cout << "Pista agregada al inventario: " << pista->obtenerDescripcion() << endl;
    } else if (pista && pista->esInteractuado()) {
        cout << "Esta pista ya ha sido recogida." << endl;
    } else {
        cerr << "Error: Pista inválida." << endl;
    }
}

// Verifica si todas las pistas clave han sido recolectadas
bool Inventario::todasLasPistasClaveRecolectadas() const {
    for (const auto& pista : pistas) {
        if (pista->esInteractuado() && !pista->esClave()) {
            return false; // Hay pistas clave no recolectadas
        }
    }
    return true;
}

// Busca una pista por su descripción
Pista* Inventario::buscarPista(const string& descripcion) const {
    for (const auto& pista : pistas) {
        if (pista->obtenerDescripcion() == descripcion) {
            return pista;
        }
    }
    return nullptr;
}

// Devuelve el número de pistas recolectadas
int Inventario::obtenerCantidadPistas() const {
    return pistas.size();
}
