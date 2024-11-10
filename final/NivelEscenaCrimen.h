#ifndef NIVELESCENACRIMEN_H
#define NIVELESCENACRIMEN_H

#include "Nivel.h"
#include <vector>
#include "Pista.h"
#include "ObjetoInteractivo.h"
using namespace std;

class NivelEscenaCrimen : public Nivel {
public:
    void iniciarNivel() override;
    void terminarNivel() override;

private:
    vector<Pista*> pistasNivel;
    vector<ObjetoInteractivo*> objetosInteractivos;
};

#endif // NIVELESCENACRIMEN_H
