#ifndef NIVELESCENACRIMEN_H
#define NIVELESCENACRIMEN_H

#include "Nivel.h"
#include <map>

/**
 * @brief Clase que representa el nivel de la escena del crimen
 */
class NivelEscenaCrimen : public Nivel {
public:
    NivelEscenaCrimen(Inventario* inventario);
    void iniciarNivel(QGraphicsScene* escena) override;
    void terminarNivel() override;

    /**
     * @brief Carga objetos interactivos en el nivel desde un mapa
     * @param objetos Mapa de objetos (ID, nombre/descripciÃ³n)
     */
    void cargarObjetos(const map<int, string>& objetos);

private:
    map<int, string> objetosMapa; ///< Mapa de objetos interactivos en el nivel
};

#endif // NIVELESCENACRIMEN_H
