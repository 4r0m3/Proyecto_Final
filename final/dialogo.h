#ifndef DIALOGO_H
#define DIALOGO_H

#include <map>
#include <string>
#include <stdexcept>
using namespace std;

/**
 * @brief Clase que representa el sistema de diÃ¡logo con personajes
 * @details Almacena preguntas y respuestas correctas, y verifica las respuestas del jugador
 */
class Dialogo {
public:
    Dialogo();

    /**
     * @brief Agrega una respuesta correcta para una pregunta especÃ­fica
     * @param idPregunta Identificador de la pregunta
     * @param respuesta Respuesta correcta asociada a la pregunta
     */
    void agregarRespuestaCorrecta(int idPregunta, const string& respuesta);

    /**
     * @brief Muestra todas las opciones de diÃ¡logo disponibles
     */
    void mostrarOpciones() const;

    /**
     * @brief Verifica si la respuesta del jugador es correcta
     * @param idPregunta Identificador de la pregunta
     * @param respuestaJugador Respuesta proporcionada por el jugador
     * @return true si la respuesta es correcta, false en caso contrario
     * @throws std::out_of_range si la pregunta no existe
     */
    bool verificarRespuesta(int idPregunta, const string& respuestaJugador) const;

private:
    map<int, string> respuestasCorrectas; ///< Almacena las respuestas correctas por ID de pregunta
};

#endif // DIALOGO_H
