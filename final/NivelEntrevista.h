#ifndef NIVELENTREVISTA_H
#define NIVELENTREVISTA_H

#include "Nivel.h"
#include "Sospechoso.h"
#include <vector>
#include <QGraphicsRectItem>  // Para crear un objeto simple sin una clase propia

/**
 * @brief Clase que representa el nivel de entrevistas a sospechosos
 */
class NivelEntrevista : public Nivel {
public:
    /**
     * @brief Constructor de NivelEntrevista
     * @param inventario Referencia al inventario compartido del juego
     */
    NivelEntrevista(Inventario* inventario, class juego* juego);

    /**
     * @brief Inicia el nivel de entrevistas
     * @param escena Escena gráfica del nivel
     */
    void iniciarNivel(QGraphicsScene* escena) override;

    /**
     * @brief Finaliza el nivel de entrevistas
     */
    void terminarNivel() override;

    /**
     * @brief Agrega un sospechoso a la escena
     * @param sospechoso Puntero al objeto Sospechoso
     */
    void agregarSospechoso(Sospechoso* sospechoso);

    /**
     * @brief Muestra la lista de sospechosos en la consola
     */
    void mostrarSospechosos() const;

    /**
     * @brief Actualiza la lógica del nivel
     */
    void actualizar() override;

private:
    vector<Sospechoso*> sospechosos; ///< Lista de sospechosos en el nivel
    QGraphicsRectItem* jefeGorgory; ///< Objeto simple que representa al jefe Gorgory
};

#endif // NIVELENTREVISTA_H



