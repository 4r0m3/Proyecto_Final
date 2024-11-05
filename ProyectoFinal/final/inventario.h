#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "Pista.h"
#include <vector>

using namespace std;

class Inventario {
public:
    void agregarPista(const Pista& pista);
    const vector<Pista>& obtenerPistas() const;
private:
    vector<Pista> pistas;

};

#endif // INVENTARIO_H
