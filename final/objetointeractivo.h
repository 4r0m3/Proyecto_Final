#ifndef OBJETOINTERACTIVO_H
#define OBJETOINTERACTIVO_H

#include <QGraphicsItem>
#include <string>

using namespace std;

/**
 * @brief Clase base abstracta para todos los objetos interactivos en el juego
 */
class ObjetoInteractivo : public QGraphicsItem {
public:
    /**
     * @brief Constructor de ObjetoInteractivo
     * @param nombre Nombre del objeto interactivo
     */
    ObjetoInteractivo(const string& nombre);

    /**
     * @brief Devuelve el nombre del objeto
     * @return Nombre del objeto
     */
    string getNombre() const;

    /**
     * @brief Define el área de colisión del objeto
     * @return Rectángulo que delimita el área del objeto
     */
    QRectF boundingRect() const override;

    /**
     * @brief Dibuja el objeto interactivo
     * @param painter Objeto QPainter para realizar el dibujo
     * @param option Opciones de estilo
     * @param widget Widget donde se dibuja el objeto
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override = 0;

    /**
     * @brief Método abstracto para manejar la interacción con el objeto
     */
    virtual void interactuar() = 0;

    /**
     * @brief Verifica si el objeto ya fue interactuado
     * @return true si ya se interactuó con el objeto, false en caso contrario
     */
    bool esInteractuado() const;

    /**
     * @brief Marca al objeto como interactuado
     */
    void marcarInteractuado();

protected:
    string nombre; ///< Nombre del objeto interactivo
    bool interactuado; ///< Estado de interacción del objeto
};

#endif // OBJETOINTERACTIVO_H

