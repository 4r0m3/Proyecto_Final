#ifndef NIVELRESOLUCION_H
#define NIVELRESOLUCION_H

#include "Nivel.h"
#include <vector>
#include "Pista.h"

class NivelResolucion : public Nivel {
public:
    void iniciarNivel() override;
    void terminarNivel() override;

private:
    std::vector<Pista*> pistasClaves;
};

#endif // NIVELRESOLUCION_H
