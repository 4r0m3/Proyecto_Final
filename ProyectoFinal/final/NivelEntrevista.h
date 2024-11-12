#ifndef NIVELENTREVISTA_H
#define NIVELENTREVISTA_H

#include "Nivel.h"
#include <vector>
#include "Sospechoso.h"

class NivelEntrevista : public Nivel {
public:
    void iniciarNivel() override;
    void terminarNivel() override;

private:
    std::vector<Sospechoso*> sospechosos;
};

#endif // NIVELENTREVISTA_H
