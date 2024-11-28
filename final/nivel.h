#ifndef NIVEL_H
#define NIVEL_H

#include <QGraphicsScene>
#include <vector>
#include <string>
#include "ObjetoInteractivo.h"
#include "Inventario.h"

using namespace std;

/**
 * @brief Clase abstracta base que representa un nivel del juego
 */
class Nivel {
public:
    /**
     * @brief Constructor de la clase Nivel
     * @param inventario Referencia al inventario compartido del juego
     */
    Nivel(Inventario* inventario);

    /**
     * @brief Destructor virtual
     */
    virtual ~Nivel();

    /**
     * @brief Método para iniciar el nivel
     * @param escena Escena gráfica del nivel
     */
    virtual void iniciarNivel(QGraphicsScene* escena) = 0;

    /**
     * @brief Método para finalizar el nivel
     */
    virtual void terminarNivel() = 0;

    /**
     * @brief Actualiza la lógica del nivel
     */
    virtual void actualizar() = 0;
    /**
    * @brief Devuelve la escena actual del nivel
     * @return Puntero a la escena del nivel
    */
    QGraphicsScene* getEscena() const;


    /**
     * @brief Agrega un objeto interactivo a la escena
     * @param objeto Objeto interactivo a agregar
     */
    void agregarObjetoInteractivo(ObjetoInteractivo* objeto);

protected:
    QGraphicsScene* escena; ///< Escena gráfica del nivel
    vector<ObjetoInteractivo*> objetosInteractivos; ///< Objetos interactivos en el nivel
    Inventario* inventario; ///< Referencia al inventario compartido
    string objetivo; ///< Descripción del objetivo del nivel
};

#endif // NIVEL_H




