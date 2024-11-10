#ifndef PISTA_H
#define PISTA_H

#include <string>
#include "ObjetoInteractivo.h"
using namespace std;

class Pista : public ObjetoInteractivo {
public:
    Pista(string descripcion, bool esRelevante);
    void inspeccionar();
    string obtenerDescripcion();
    void marcarComoRelevante();

private:
    string descripcion;
    bool esRelevante;
};

#endif // PISTA_H
