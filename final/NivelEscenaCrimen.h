#ifndef NIVELESCENACRIMEN_H
#define NIVELESCENACRIMEN_H

#include "Nivel.h"
#include "Pista.h"
#include "Sospechoso.h"
#include "Inventario.h"
#include "Lisa.h"
#include "juego.h"  // Asegúrate de incluir juego.h para que se reconozca la clase juego

using namespace std;

/**
 * @brief Clase que representa el nivel de la escena del crimen.
 */
class NivelEscenaCrimen : public Nivel {
private:
    map<int, string> objetosMapa; ///< Mapa que almacena las pistas y sus descripciones
    int pistasRecolectadas; ///< Número de pistas recolectadas en el nivel
    juego* juego;  ///< Puntero a la clase juego

public:
    /**
     * @brief Constructor del nivel de la escena del crimen.
     * @param inventario Puntero al inventario compartido del juego.
     * @param juego Puntero a la clase juego.
     */
    NivelEscenaCrimen(Inventario* inventario, class juego* juego);  // Aceptar puntero a juego

    /**
     * @brief Inicia el nivel de la escena del crimen.
     * @param escena Puntero a la escena gráfica que se usará para el nivel.
     */
    void iniciarNivel(QGraphicsScene* escena) override;

    /**
     * @brief Termina el nivel de la escena del crimen.
     */
    void terminarNivel() override;

    /**
     * @brief Carga los objetos interactivos (pistas) en el nivel.
     * @param objetos Mapa de objetos interactivos (pistas).
     */
    void cargarObjetos(const map<int, string>& objetos);

    /**
     * @brief Actualiza el estado del nivel (verifica si se han recolectado todas las pistas).
     */
    void actualizar() override;
};

#endif // NIVELESCENACRIMEN_H
