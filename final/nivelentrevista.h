#ifndef NIVELENTREVISTA_H
#define NIVELENTREVISTA_H

#include "Nivel.h"
#include "Sospechoso.h"
#include <vector>

/**
 * @brief Clase que representa el nivel de entrevista a sospechosos
 */
class NivelEntrevista : public Nivel {
public:
    NivelEntrevista(Inventario* inventario);
    void iniciarNivel(QGraphicsScene* escena) override;
    void terminarNivel() override;

    /**
     * @brief Agrega un sospechoso al nivel
     * @param sospechoso Puntero al sospechoso a agregar
     */
    void agregarSospechoso(Sospechoso* sospechoso);

    /**
     * @brief Muestra informaciÃ³n de los sospechosos disponibles
     */
    void mostrarSospechosos() const;

private:
    vector<Sospechoso*> sospechosos; ///< Lista de sospechosos en el nivel
};

#endif // NIVELENTREVISTA_H

