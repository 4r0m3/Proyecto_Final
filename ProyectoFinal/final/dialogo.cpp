#include "Dialogo.h"

Dialogo::Dialogo(const Sospechoso& sospechoso) : sospechoso(sospechoso) {
    respuestaCorrecta = "No fui yo.";  // Ejemplo de respuesta correcta
}

bool Dialogo::verificarRespuesta(const std::string& respuesta) {
    return respuesta == respuestaCorrecta;
}
