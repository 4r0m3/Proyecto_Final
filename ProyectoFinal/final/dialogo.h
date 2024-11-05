#ifndef DIALOGO_H
#define DIALOGO_H
#include "Sospechoso.h"
#include <string>

using namespace std;
class Dialogo
{
public:
    Dialogo(const Sospechoso& sospechoso);
    bool verificarRespuesta(const string& respuesta);
private:
    Sospechoso sospechoso;
    string respuestaCorrecta;
};

#endif // DIALOGO_H
