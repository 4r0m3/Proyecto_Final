#ifndef NIVEL_H
#define NIVEL_H

#include <QGraphicsScene>
#include <vector>
#include <map>
#include <string>
#include "ObjetoInteractivo.h"
#include "Pista.h"
#include "Inventario.h"

using namespace std;

/**
 * @brief Clase abstracta base que representa un nivel del juego
 */
class Nivel {
public:
    Nivel(Inventario* inventario);
    virtual ~Nivel();

    /**
     * @brief MÃ©todo para iniciar el nivel
     */
    virtual void iniciarNivel(QGraphicsScene* escena) = 0;

    /**
     * @brief MÃ©todo para finalizar el nivel
     */
    virtual void terminarNivel() = 0;

    /**
     * @brief Agrega un objeto interactivo a la escena
     * @param objeto Objeto interactivo a agregar
     */
    void agregarObjetoInteractivo(ObjetoInteractivo* objeto);

    /**
     * @brief Muestra los objetos interactivos disponibles en el nivel
     */
    void mostrarObjetosInteractivos() const;

protected:
    QGraphicsScene* escena; ///< Escena grÃ¡fica del nivel
    vector<ObjetoInteractivo*> objetosInteractivos; ///< Objetos interactivos en el nivel
    Inventario* inventario; ///< Referencia al inventario compartido
    string objetivo; ///< DescripciÃ³n del objetivo del nivel
};

#endif // NIVEL_H

