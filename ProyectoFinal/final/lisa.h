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
    QPixmap sprite;           ///< Imagen del personaje
    qreal velocidad;          ///< Velocidad de movimiento del personaje
    bool movingLeft;          ///< Estado de movimiento hacia la izquierda
    bool movingRight;         ///< Estado de movimiento hacia la derecha
    bool movingUp;            ///< Estado de movimiento hacia arriba
    bool movingDown;          ///< Estado de movimiento hacia abajo
    Juego* juego;             ///< Referencia a la clase Juego para acceder al inventario y otras funciones

public:
    /**
     * @brief Constructor de la clase Lisa
     * @param parent Puntero al item padre (opcional)
     */
    Lisa(Juego* juego, QGraphicsItem* parent = nullptr);

    /**
     * @brief Destructor virtual por defecto
     */
    ~Lisa() override = default;

    /**
     * @brief Define el rectÃ¡ngulo que contiene al personaje
     * @return QRectF que representa el Ã¡rea del personaje
     */
    QRectF boundingRect() const override;

    /**
     * @brief MÃ©todo para dibujar el personaje en la escena
     * @param painter Objeto para realizar el dibujado
     * @param option Opciones de estilo para el dibujado
     * @param widget Widget donde se dibujarÃ¡
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

    /**
     * @brief Establece la direcciÃ³n de movimiento del personaje
     * @param left Estado de movimiento izquierdo
     * @param right Estado de movimiento derecho
     * @param up Estado de movimiento hacia arriba
     * @param down Estado de movimiento hacia abajo
     */
    void setMovementDirection(bool left, bool right, bool up, bool down);

    /**
     * @brief Realiza el movimiento del personaje segÃºn su estado actual
     */
    void mover();

    /**
     * @brief Detiene todo movimiento del personaje
     */
    void detener();

    /**
     * @brief Detecta colisiÃ³n con otro item de la escena y maneja la interacciÃ³n
     * @param item Item con el que se quiere detectar la colisiÃ³n
     * @return true si hay colisiÃ³n, false en caso contrario
     */
    bool detectarColision(const QGraphicsItem* item);

protected:
    /**
     * @brief MÃ©todo llamado automÃ¡ticamente para actualizar el personaje
     * @param phase Fase de la actualizaciÃ³n
     */
    void advance(int phase) override;

private:
    /**
     * @brief Carga la imagen del sprite del personaje
     */
    void cargarSprite();
};

#endif // LISA_H
