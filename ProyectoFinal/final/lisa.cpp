#include "lisa.h"
#include <iostream>

// Constructor de Lisa, inicializa el sprite y la referencia a la clase Juego
Lisa::Lisa(Juego* juego, QGraphicsItem* parent)
    : QGraphicsItem(parent), juego(juego), velocidad(5.0), movingLeft(false), movingRight(false), movingUp(false), movingDown(false) {
    cargarSprite();
}

// Define el Ã¡rea que ocupa Lisa en la escena
QRectF Lisa::boundingRect() const {
    return QRectF(0, 0, sprite.width(), sprite.height());
}

// Dibuja el sprite de Lisa en la escena
void Lisa::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawPixmap(0, 0, sprite);
}

// Define la direcciÃ³n de movimiento del personaje
void Lisa::setMovementDirection(bool left, bool right, bool up, bool down) {
    movingLeft = left;
    movingRight = right;
    movingUp = up;
    movingDown = down;
}

// Realiza el movimiento en la direcciÃ³n especificada
void Lisa::mover() {
    if (movingLeft) {
        setX(x() - velocidad);
    }
    if (movingRight) {
        setX(x() + velocidad);
    }
    if (movingUp) {
        setY(y() - velocidad);
    }
    if (movingDown) {
        setY(y() + velocidad);
    }
}

// Detiene el movimiento del personaje
void Lisa::detener() {
    movingLeft = movingRight = movingUp = movingDown = false;
}

// Detecta colisiones y maneja interacciÃ³n con objetos interactivos
bool Lisa::detectarColision(const QGraphicsItem* item) {
    if (collidesWithItem(item)) {
        auto* pista = dynamic_cast<const Pista*>(item);
        if (pista) {
            // Agrega la pista al inventario de Juego
            juego->getInventario()->agregarPista(const_cast<Pista*>(pista));  // Agregar pista al inventario
            std::cout << "Pista recogida: " << pista->obtenerDescripcion() << std::endl;
            return true;
        }
    }
    return false;
}

// MÃ©todo para actualizar Lisa en cada fase del ciclo del juego
void Lisa::advance(int phase) {
    if (!phase) return;
    mover(); // Actualiza el movimiento en cada ciclo
}

// Carga la imagen del sprite del personaje
void Lisa::cargarSprite() {
    sprite = QPixmap(":/images/lisa.png"); // AsegÃºrate de que la ruta sea correcta
}
