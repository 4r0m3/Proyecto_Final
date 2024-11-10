#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Pista.h"

class Inventario {
public:
    void agregarPista(Pista* pista);
    void mostrarInventario();

private:
    std::vector<Pista*> pistas;
};

#endif // INVENTARIO_H
