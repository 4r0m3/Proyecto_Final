#ifndef NIVELRESOLUCION_H
#define NIVELRESOLUCION_H

#include "Nivel.h"
#include <string>

/**
 * @brief Clase que representa el nivel de resolución del caso
 */
class NivelResolucion : public Nivel {
public:
    /**
     * @brief Constructor de NivelResolucion
     * @param inventario Referencia al inventario compartido del juego
     */
    NivelResolucion(Inventario* inventario);

    /**
     * @brief Inicia el nivel de resolución
     * @param escena Escena gráfica del nivel
     */
    void iniciarNivel(QGraphicsScene* escena) override;

    /**
     * @brief Finaliza el nivel de resolución
     */
    void terminarNivel() override;

    /**
     * @brief Resuelve el caso seleccionando al culpable
     * @param sospechoso Nombre del sospechoso elegido
     */
    void resolverCaso(const string& sospechoso);

    /**
     * @brief Actualiza la lógica del nivel
     */
    void actualizar() override;

private:
    string culpable; ///< Culpable real del caso
};

#endif // NIVELRESOLUCION_H


