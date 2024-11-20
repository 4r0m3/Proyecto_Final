#ifndef OBJETOINTERACTIVO_H
#define OBJETOINTERACTIVO_H

#include <QGraphicsItem>
#include <string>

using namespace std;

/**
 * @brief Clase abstracta base para todos los objetos interactivos
 */
class ObjetoInteractivo : public QGraphicsItem {
public:
    ObjetoInteractivo(const string& nombre);
    virtual ~ObjetoInteractivo() = default;

    /**
     * @brief Devuelve el nombre del objeto interactivo
     * @return Nombre del objeto
     */
    string getNombre() const;

    /**
     * @brief MÃ©todo abstracto para manejar la interacciÃ³n con el objeto
     */
    virtual void interactuar() = 0;

protected:
    string nombre; ///< Nombre descriptivo del objeto interactivo
    QRectF boundingRect() const override; ///< Define el Ã¡rea de colisiÃ³n del objeto
};

#endif // OBJETOINTERACTIVO_H
