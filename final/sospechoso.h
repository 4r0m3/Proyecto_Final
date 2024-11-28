#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include "ObjetoInteractivo.h"
#include <map>
#include <string>

using namespace std;

/**
 * @brief Clase que representa a un sospechoso en el juego
 */
class Sospechoso : public ObjetoInteractivo {
public:
    /**
     * @brief Constructor de Sospechoso
     * @param nombre Nombre del sospechoso
     */
    Sospechoso(const string& nombre);

    /**
     * @brief Maneja la interacción con el sospechoso
     */
    void interactuar() override;

    /**
     * @brief Devuelve el nombre del sospechoso
     * @return Nombre del sospechoso
     */
    string obtenerNombre() const;

    /**
     * @brief Agrega una respuesta posible a una pregunta
     * @param idPregunta ID de la pregunta
     * @param respuesta Respuesta asociada
     */
    void agregarRespuesta(int idPregunta, const string& respuesta);

    /**
     * @brief Obtiene la respuesta a una pregunta específica
     * @param idPregunta ID de la pregunta
     * @return Respuesta asociada o un mensaje si no existe
     */
    string obtenerRespuesta(int idPregunta) const;

    /**
     * @brief Verifica si el sospechoso ya ha sido entrevistado
     * @return true si fue entrevistado, false en caso contrario
     */
    bool haSidoEntrevistado() const;

    /**
     * @brief Marca al sospechoso como entrevistado
     */
    void marcarEntrevistado();

private:
    map<int, string> respuestas; ///< Respuestas posibles del sospechoso
    bool entrevistado; ///< Indica si el sospechoso ya fue entrevistado
};

#endif // SOSPECHOSO_H

