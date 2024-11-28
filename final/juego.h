#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include "Nivel.h"
#include "Inventario.h"

/**
 * @brief Clase que gestiona el flujo general del juego
 */
class juego {
public:
    /**
     * @brief Constructor de la clase juego
     */
    juego();

    /**
     * @brief Destructor de la clase juego
     */
    ~juego();

    /**
     * @brief Inicia el juego desde el primer nivel
     */
    void iniciarJuego();

    /**
     * @brief Carga el nivel especificado
     * @param nivelID Identificador del nivel a cargar
     */
    void cargarNivel(int nivelID);

    /**
     * @brief Muestra el inventario actual
     */
    void mostrarInventario() const;

    /**
     * @brief Retorna un puntero al inventario actual
     * @return Puntero al objeto `Inventario`
     */
    Inventario* getInventario() const;

    /**
     * @brief Devuelve la escena actual del nivel cargado
     * @return Puntero a `QGraphicsScene` del nivel actual
     */
    QGraphicsScene* getEscenaActual() const;

    /**
     * @brief Verifica si un nivel ha sido completado
     * @param nivelID Identificador del nivel
     * @return true si el nivel ha sido completado, false en caso contrario
     */
    bool nivelCompletado(int nivelID) const;

private:
    Inventario* inventario; ///< Inventario compartido entre los niveles
    Nivel* nivelActual; ///< Puntero al nivel actualmente cargado
    int nivelActualID; ///< Identificador del nivel actual

};

#endif // JUEGO_H

