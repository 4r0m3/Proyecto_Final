#include "Juego.h"

Juego::Juego() : inventario(new Inventario()), nivelActual(nullptr), puntosVerdad(0), nivelActualID(0) {}

void Juego::iniciarJuego() {
    // LÃ³gica para iniciar el juego
}

void Juego::cargarNivel(int nivelID) {
    // LÃ³gica para cargar el nivel
}

void Juego::mostrarInventario() {
    // LÃ³gica para mostrar el inventario
}

void Juego::actualizarPuntosVerdad(int puntos) {
    puntosVerdad += puntos;
}
