#ifndef NIVELESCENACRIMEN_H
#define NIVELESCENACRIMEN_H

#include "Nivel.h"
#include <map>
#include <string>

/**
 * @brief Clase que representa el nivel de la escena del crimen
 */
class NivelEscenaCrimen : public Nivel {
public:
    /**
     * @brief Constructor de NivelEscenaCrimen
     * @param inventario Referencia al inventario compartido del juego
     */
    NivelEscenaCrimen(Inventario* inventario);

    /**
     * @brief Inicia el nivel de la escena del crimen
     * @param escena Escena gráfica del nivel
     */
    void iniciarNivel(QGraphicsScene* escena) override;

    /**
     * @brief Finaliza el nivel de la escena del crimen
     */
    void terminarNivel() override;

    /**
     * @brief Carga los objetos de pistas en el nivel
     * @param objetos Mapa con el ID y descripción de cada pista
     */
    void cargarObjetos(const map<int, string>& objetos);

    /**
     * @brief Actualiza la lógica del nivel
     */
    void actualizar() override;

private:
    map<int, string> objetosMapa; ///< Mapa con los objetos de la escena
};

#endif // NIVELESCENACRIMEN_H

