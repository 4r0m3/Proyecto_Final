#include "Sospechoso.h"
#include <iostream>

Sospechoso::Sospechoso(std::string nombre) : nombre(nombre) {}

std::string Sospechoso::darRespuesta(int pregunta) {
    return respuestas.count(pregunta) ? respuestas[pregunta] : "Respuesta no disponible";
}

void Sospechoso::mostrarInformacion() {
    std::cout << "InformaciÃ³n de sospechoso: " << nombre << std::endl;
}
