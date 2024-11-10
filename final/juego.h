#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Nivel.h"
#include "Inventario.h"

class Juego {
public:
    Juego();
    void iniciarJuego();
    void cargarNivel(int nivelID);
    void mostrarInventario();
    void actualizarPuntosVerdad(int puntos);

private:
    Inventario* inventario;
    Nivel* nivelActual;
    int puntosVerdad;
    int nivelActualID;
};

#endif // JUEGO_H
