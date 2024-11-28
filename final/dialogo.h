#ifndef DIALOGO_H
#define DIALOGO_H

#include <map>
#include <string>
#include <QGraphicsScene>
#include <QString>
#include "Sospechoso.h"

using namespace std;

/**
 * @brief Clase que gestiona los diálogos en el juego
 */
class Dialogo {
public:
    /**
     * @brief Constructor por defecto de Dialogo
     */
    Dialogo();

    /**
     * @brief Agrega una respuesta correcta asociada a una pregunta
     * @param idPregunta ID único de la pregunta
     * @param respuesta Respuesta correcta asociada
     */
    void agregarRespuestaCorrecta(int idPregunta, const string& respuesta);

    /**
     * @brief Muestra todas las opciones de diálogo disponibles (debugging)
     */
    void mostrarOpciones() const;

    /**
     * @brief Verifica si la respuesta del jugador es correcta
     * @param idPregunta ID único de la pregunta
     * @param respuestaJugador Respuesta proporcionada por el jugador
     * @return true si la respuesta es correcta, false en caso contrario
     */
    bool verificarRespuesta(int idPregunta, const string& respuestaJugador) const;

    /**
     * @brief Inicia un diálogo con un sospechoso
     * @param sospechoso Puntero al sospechoso con el que se interactúa
     * @param escena Escena gráfica donde se mostrarán los diálogos
     */
    void iniciarDialogo(Sospechoso* sospechoso, QGraphicsScene* escena);

    /**
     * @brief Muestra una burbuja de diálogo en la parte baja de la pantalla
     * @param texto Texto a mostrar en la burbuja
     * @param escena Escena gráfica donde se mostrará la burbuja
     */
    void mostrarBurbuja(const QString& texto, QGraphicsScene* escena);

private:
    map<int, string> respuestasCorrectas; ///< Respuestas correctas asociadas a preguntas
};

#endif // DIALOGO_H
