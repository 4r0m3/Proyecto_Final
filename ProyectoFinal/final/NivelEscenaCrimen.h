#ifndef NIVELESCENACRIMEN_H
#define NIVELESCENACRIMEN_H

#include "nivel.h"
#include <vector>
#include "pista.h"
#include "objetointeractivo.h"

using namespace std;

/**
 * @brief Clase que representa el nivel de la escena del crimen
 * @details Permite recolectar pistas en el nivel
 */
class NivelEscenaCrimen : public Nivel {
public:
    NivelEscenaCrimen();
    void iniciarNivel() override;
    void terminarNivel() override;

    /**
     * @brief Agrega un objeto interactivo a la escena
     * @param objeto Puntero al objeto interactivo
     */
    void agregarObjetoInteractivo(ObjetoInteractivo* objeto);

    /**
     * @brief Muestra las pistas recolectadas en este nivel
     */
    void mostrarPistasRecolectadas() const;

private:
    vector<Pista*> pistasNivel; ///< Vector de pistas encontradas en la escena del crimen
    vector<ObjetoInteractivo*> objetosInteractivos; ///< Objetos interactivos disponibles en el nivel
};

#endif // NIVELESCENACRIMEN_H
