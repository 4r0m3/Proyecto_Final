#ifndef PISTA_H
#define PISTA_H

#include "ObjetoInteractivo.h"

/**
 * @brief Clase que representa una pista en el juego
 */
class Pista : public ObjetoInteractivo {
public:
    Pista(const string& descripcion, bool esClave);
    void interactuar() override;

    /**
     * @brief Devuelve la descripción de la pista
     * @return Descripción de la pista
     */
    string obtenerDescripcion() const;

    /**
     * @brief Marca la pista como clave
     */
    void marcarComoClave();

    /**
     * @brief Define el área del objeto en la escena
     * @return Área rectangular del objeto
     */
    QRectF boundingRect() const override;

    /**
     * @brief Dibuja el objeto en la escena
     * @param painter Objeto de dibujo
     * @param option Opciones de estilo
     * @param widget Widget asociado (opcional)
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

private:
    string descripcion; ///< Descripción de la pista
    bool esClave; ///< Indica si la pista es clave para el progreso del juego
};

#endif // PISTA_H

