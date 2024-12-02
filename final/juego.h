#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "Inventario.h"
#include "Nivel.h"

// Forward declaration para evitar inclusiones circulares
class Lisa;

class juego {
private:
    Inventario* inventario;         ///< Referencia al inventario del juego
    Nivel* nivelActual;             ///< Puntero al nivel actual
    int nivelActualID;              ///< ID del nivel actual
    QGraphicsView* vista;           ///< Vista gráfica para centrarla en Lisa
    int pistasRecolectadas;         ///< Contador de pistas recolectadas en el nivel 1
    int sospechososEntrevistados;   ///< Contador de sospechosos entrevistados en el nivel 2

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
     * @param vista Puntero a la instancia de QGraphicsView para manejar la vista
     */
    void iniciarJuego(QGraphicsView* vista);

    /**
     * @brief Carga un nivel específico
     * @param nivelID ID del nivel a cargar
     */
    void cargarNivel(int nivelID);

    /**
     * @brief Método para centrar la vista en Lisa
     */
    void centrarVistaEnLisa() const;

    /**
     * @brief Método para registrar pistas recolectadas en el nivel 1
     */
    void registrarPista();

    /**
     * @brief Método para registrar sospechosos entrevistados en el nivel 2
     */
    void registrarEntrevista();

    /**
     * @brief Método para verificar si un nivel ha sido completado
     * @param nivelID ID del nivel a verificar
     * @return true si el nivel fue completado, false en caso contrario
     */
    bool nivelCompletado(int nivelID) const;

    /**
     * @brief Devuelve la escena gráfica del nivel actual
     * @return Puntero a la escena gráfica
     */
    QGraphicsScene* getEscenaActual() const;

    /**
     * @brief Devuelve el puntero a la vista actual del juego
     * @return Puntero a QGraphicsView
     */
    QGraphicsView* getVista() const {
        return vista;
    }

    /**
     * @brief Devuelve el inventario del juego
     * @return Puntero al inventario
     */
    Inventario* getInventario() const {
        return inventario;
    }
};

#endif // JUEGO_H
