#ifndef NIVEL_H
#define NIVEL_H

#include <QGraphicsScene>
#include <vector>
#include "ObjetoInteractivo.h"
#include "Inventario.h"
#include "Lisa.h"

using namespace std;

/**
 * @brief Clase abstracta que representa un nivel en el juego.
 */
class Nivel {
protected:
    QGraphicsScene* escena;                   ///< Escena gráfica del nivel
    vector<ObjetoInteractivo*> objetosInteractivos; ///< Objetos interactivos en el nivel
    Inventario* inventario;                   ///< Referencia al inventario compartido
    Lisa* lisa;                               ///< Referencia a Lisa en el nivel
    string objetivo;                          ///< Descripción del objetivo del nivel

public:
    /**
     * @brief Constructor de la clase Nivel.
     * @param inventario Puntero al inventario compartido del juego.
     */
    Nivel(Inventario* inventario, juego* juego);

    /**
     * @brief Destructor virtual.
     */
    virtual ~Nivel();

    /**
     * @brief Método puro para iniciar el nivel.
     * @param escena Puntero a la escena gráfica que se usará para el nivel.
     */
    virtual void iniciarNivel(QGraphicsScene* escena) = 0;

    /**
     * @brief Método puro para finalizar el nivel.
     */
    virtual void terminarNivel() = 0;

    virtual void actualizar () = 0;

    /**
     * @brief Devuelve la escena gráfica del nivel.
     * @return Puntero a la escena gráfica.
     */
    QGraphicsScene* getEscena() const;

    /**
     * @brief Devuelve el puntero a Lisa del nivel.
     * @return Puntero a Lisa.
     */
    Lisa* getLisa() const;

    /**
     * @brief Asigna a Lisa al nivel.
     * @param nuevaLisa Puntero a Lisa que se agregará al nivel.
     */
    void asignarLisa(Lisa* nuevaLisa);

    /**
     * @brief Agrega un objeto interactivo al nivel.
     * @param objeto Puntero al objeto interactivo que se agregará.
     */
    void agregarObjetoInteractivo(ObjetoInteractivo* objeto);
};

#endif // NIVEL_H



