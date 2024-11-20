#ifndef NIVELRESOLUCION_H
#define NIVELRESOLUCION_H

#include "Nivel.h"
#include <string>

/**
 * @brief Clase que representa el nivel de resoluciÃ³n del caso
 */
class NivelResolucion : public Nivel {
public:
    NivelResolucion(Inventario* inventario);
    void iniciarNivel(QGraphicsScene* escena) override;
    void terminarNivel() override;

    /**
     * @brief Resuelve el caso eligiendo al culpable
     * @param sospechoso Nombre del sospechoso elegido
     */
    void resolverCaso(const string& sospechoso);

private:
    string culpable; ///< Culpable real del caso
};

#endif // NIVELRESOLUCION_H
