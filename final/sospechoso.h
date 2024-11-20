#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include "ObjetoInteractivo.h"
#include <map>

/**
 * @brief Clase que representa un sospechoso en el nivel de entrevistas
 */
class Sospechoso : public ObjetoInteractivo {
public:
    Sospechoso(const string& nombre);
    void interactuar() override;

    /**
     * @brief Devuelve el nombre del sospechoso
     * @return Nombre del sospechoso
     */
    string obtenerNombre() const;

    /**
     * @brief Agrega una respuesta posible para una pregunta basada en pistas
     * @param idPregunta ID de la pregunta
     * @param respuesta Respuesta asociada a la pregunta
     */
    void agregarRespuesta(int idPregunta, const string& respuesta);

    /**
     * @brief Obtiene la respuesta a una pregunta especÃ­fica
     * @param idPregunta ID de la pregunta
     * @return Respuesta asociada a la pregunta
     */
    string obtenerRespuesta(int idPregunta) const;

private:
    map<int, string> respuestas; ///< Respuestas basadas en preguntas especÃ­ficas
};

#endif // SOSPECHOSO_H

