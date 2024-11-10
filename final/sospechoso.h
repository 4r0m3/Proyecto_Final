#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include <string>
#include <map>
using namespace std;

class Sospechoso {
public:
    Sospechoso(string nombre);
    string darRespuesta(int pregunta);
    void mostrarInformacion();

private:
    string nombre;
    map<int, string> respuestas;
};

#endif // SOSPECHOSO_H
