#ifndef DIALOGO_H
#define DIALOGO_H

#include <map>
#include <string>

class Dialogo {
public:
    Dialogo();
    void mostrarOpciones();
    bool verificarRespuesta(int idPregunta, std::string respuestaJugador);

private:
    std::map<int, std::string> respuestasCorrectas;
};

#endif // DIALOGO_H
