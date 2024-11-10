#include "Dialogo.h"
#include <iostream>

Dialogo::Dialogo() {}

void Dialogo::mostrarOpciones() {
    // LÃ³gica para mostrar opciones de diÃ¡logo
}

bool Dialogo::verificarRespuesta(int idPregunta, std::string respuestaJugador) {
    return respuestasCorrectas.count(idPregunta) && respuestasCorrectas[idPregunta] == respuestaJugador;
}
