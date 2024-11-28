#ifndef LISA_H
#define LISA_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include "juego.h"  // Incluye la referencia a Juego para acceder al inventario
#include "Pista.h"

/**
 * @brief Clase que representa al personaje principal Lisa Simpson
 * @details Hereda de QGraphicsItem para poder ser renderizada en la escena
 */
class Lisa : public QGraphicsItem {
private:
    QPixmap spriteFrontal;    ///< Sprite de Lisa de frente
    QPixmap spriteTrasero;    ///< Sprite de Lisa de espaldas
    QPixmap spriteIzquierda;  ///< Sprite de Lisa caminando a la izquierda
    QPixmap spriteDerecha;    ///< Sprite de Lisa caminando a la derecha
    QPixmap spriteActual;     ///< Sprite actual a mostrar
    qreal velocidad;          ///< Velocidad de movimiento del personaje
    class juego* juego;       ///< Referencia a la clase Juego para acceder al inventario y otras funciones
    bool movingLeft;          ///< Estado de movimiento hacia la izquierda
    bool movingRight;         ///< Estado de movimiento hacia la derecha
    bool movingUp;            ///< Estado de movimiento hacia arriba
    bool movingDown;          ///< Estado de movimiento hacia abajo

public:
    /**
     * @brief Constructor de la clase Lisa
     * @param juego Puntero a la instancia de juego para acceder al inventario
     * @param parent Puntero al item padre (opcional)
     */
    Lisa(class juego* juego, QGraphicsItem* parent = nullptr);

    /**
     * @brief Destructor virtual por defecto
     */
    ~Lisa() override = default;

    /**
     * @brief Define el rectángulo que contiene al personaje
     * @return QRectF que representa el área del personaje
     */
    QRectF boundingRect() const override;

    /**
     * @brief Método para dibujar el personaje en la escena
     * @param painter Objeto para realizar el dibujado
     * @param option Opciones de estilo para el dibujado
     * @param widget Widget donde se dibujará
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

    /**
     * @brief Establece la dirección de movimiento del personaje
     * @param left Estado de movimiento izquierdo
     * @param right Estado de movimiento derecho
     * @param up Estado de movimiento hacia arriba
     * @param down Estado de movimiento hacia abajo
     */
    void setMovementDirection(bool left, bool right, bool up, bool down);

    /**
     * @brief Realiza el movimiento del personaje según su estado actual
     */
    void mover();

    /**
     * @brief Detiene todo movimiento del personaje
     */
    void detener();

    /**
     * @brief Detecta colisión con otro item de la escena y maneja la interacción
     * @param item Item con el que se quiere detectar la colisión
     * @return true si hay colisión, false en caso contrario
     */
    bool detectarColision(const QGraphicsItem* item);

protected:
    /**
     * @brief Método llamado automáticamente para actualizar el personaje
     * @param phase Fase de la actualización
     */
    void advance(int phase) override;

private:
    /**
     * @brief Carga todos los sprites del personaje
     */
    void cargarSprites();

    /**
     * @brief Cambia el sprite actual según la dirección de movimiento
     * @param direction Dirección del movimiento (frontal, trasero, izquierda, derecha)
     */
    void actualizarSprite(const QString& direction);
};

#endif // LISA_H

