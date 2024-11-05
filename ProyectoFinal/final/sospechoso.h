#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H
#include <vector>
#include <string>
using namespace std;

class Sospechoso {
public:
    Sospechoso(const string& nombre, const string& descripcion);
    string darRespuesta(); //devuelve una respuesta
private:
    string nombre;
    string descripcion;
    vector<string> respuestas;

};

#endif // SOSPECHOSO_H
