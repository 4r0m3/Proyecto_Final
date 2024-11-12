#include "inventario.h"
#include <iostream>
using namespace std;
// Constructor por defecto
Inventario::Inventario() {}

// Agrega una pista al inventario
void Inventario::agregarPista(Pista* pista) {
    if (pista) {
        pistas.push_back(pista);
        cout << "Pista agregada al inventario: " << pista->obtenerDescripcion() << endl;
    } else {
        cerr << "Error: Pista invÃ¡lida." << endl;
    }
}

// Muestra las pistas en el inventario
void Inventario::mostrarInventario() const {
    cout << "Inventario de Pistas:" << endl;
    for (const auto& pista : pistas) {
        cout << "- " << pista->obtenerDescripcion() << endl;
    }
}

// Busca una pista por su descripciÃ³n
Pista* Inventario::buscarPista(const string& descripcion) const {
    for (const auto& pista : pistas) {
        if (pista->obtenerDescripcion() == descripcion) {
            return pista;
        }
    }
    return nullptr;
}
