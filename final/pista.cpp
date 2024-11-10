#include "Pista.h"
#include <iostream>

Pista::Pista(std::string descripcion, bool esRelevante)
    : ObjetoInteractivo("Pista"), // Llamada al constructor de la clase base
    descripcion(descripcion), esRelevante(esRelevante) {}

void Pista::inspeccionar() {
    std::cout << "DescripciÃ³n: " << descripcion << std::endl;
}

std::string Pista::obtenerDescripcion() {
    return descripcion;
}

void Pista::marcarComoRelevante() {
    esRelevante = true;
}
