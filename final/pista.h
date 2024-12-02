#ifndef PISTA_H
#define PISTA_H

#include "ObjetoInteractivo.h"
#include <string>

using namespace std;

/**
 * @brief Clase que representa una pista interactuable en el juego
 * @details Hereda de ObjetoInteractivo y tiene atributos adicionales
 *          para describir y marcar una pista como clave para el caso.
 */
class Pista : public ObjetoInteractivo {
private:
    string descripcion; ///< Descripción detallada de la pista
    bool Clave;       ///< Indica si la pista es clave para resolver el caso
    bool interactuado;  ///< Indica si la pista ya fue recogida/interactuada

public:
    /**
     * @brief Constructor de la clase Pista
     * @param descripcion Descripción de la pista
     * @param esClave Indica si la pista es clave para el caso
     */
    Pista(const QString& descripcion, bool esClave);

    bool esClave() const;        ///< Método público para acceder al estado de 'clave'


    /**
     * @brief Maneja la interacción con la pista
     */
    void interactuar() override;

    /**
     * @brief Devuelve la descripción de la pista
     * @return Descripción como string
     */
    string obtenerDescripcion() const;

    /**
     * @brief Marca la pista como clave
     */
    void marcarComoClave();

    /**
     * @brief Verifica si la pista ya fue interactuada
     * @return true si ya fue interactuada, false en caso contrario
     */
    bool esInteractuado() const;

    /**
     * @brief Define el área gráfica del objeto en la escena
     * @return Rectángulo que representa el área de la pista
     */
    QRectF boundingRect() const override;

    /**
     * @brief Dibuja la pista en la escena gráfica
     * @param painter Objeto para realizar el dibujado
     * @param option Opciones de estilo para el dibujado
     * @param widget Widget donde se dibujará
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
};

#endif // PISTA_H
