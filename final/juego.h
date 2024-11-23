#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Nivel.h"
#include "inventario.h"

using namespace std;

/**
 * @brief Clase principal que controla el flujo del juego
 * @details Gestiona el inventario, los niveles y el progreso del jugador
 */
class juego {
public:
    juego();
    ~juego();

    /**
     * @brief Inicia el juego y carga el primer nivel
     */
    void iniciarJuego();

    /**
     * @brief Carga un nivel especÃ­fico por su ID
     * @param nivelID ID del nivel a cargar
     */
    void cargarNivel(int nivelID);

    /**
     * @brief Muestra el contenido actual del inventario
     */
    void mostrarInventario() const;

    /**
     * @brief Acceso al inventario del juego
     * @return Puntero al inventario actual del juego
     */
    Inventario* getInventario() const;

private:
    Inventario* inventario; ///< Inventario de pistas recolectadas por el jugador
    Nivel* nivelActual; ///< Puntero al nivel actual
    int puntosVerdad; ///< Puntaje de progreso en el juego
    int nivelActualID; ///< ID del nivel actual
};

#endif // JUEGO_H
