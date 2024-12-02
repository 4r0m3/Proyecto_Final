#include "lisa.h"
#include <iostream>
#include <QGraphicsView>
#include <juego.h>
#include <pista.h>
#include <sospechoso.h>

Lisa::Lisa(class juego* juego, QGraphicsItem* parent)
    : QGraphicsItem(parent), juego(juego), velocidad(5.0), movingLeft(false), movingRight(false), movingUp(false), movingDown(false) {
    cargarSprites();
    spriteActual = spriteFrontal; // Lisa inicia con el sprite frontal
    setPos(400, 300); // Posición inicial de Lisa, puede ajustarse
}

// Define el área que ocupa Lisa en la escena
QRectF Lisa::boundingRect() const {
    return QRectF(0, 0, spriteActual.width(), spriteActual.height());
}

// Dibuja el sprite actual de Lisa en la escena
void Lisa::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawPixmap(0, 0, spriteActual);
}

// Define la dirección de movimiento del personaje
void Lisa::setMovementDirection(bool left, bool right, bool up, bool down) {
    movingLeft = left;
    movingRight = right;
    movingUp = up;
    movingDown = down;

    // Actualizar el sprite según la dirección
    if (movingLeft) {
        actualizarSprite("izquierda");
    } else if (movingRight) {
        actualizarSprite("derecha");
    } else if (movingUp) {
        actualizarSprite("trasero");
    } else if (movingDown) {
        actualizarSprite("frontal");
    }
}

// Realiza el movimiento en la dirección especificada
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

    // Asegura que Lisa permanezca dentro de los límites de la escena
    if (scene()) {
        QRectF bounds = scene()->sceneRect();
        if (x() < bounds.left()) setX(bounds.left());
        if (x() + boundingRect().width() > bounds.right()) setX(bounds.right() - boundingRect().width());
        if (y() < bounds.top()) setY(bounds.top());
        if (y() + boundingRect().height() > bounds.bottom()) setY(bounds.bottom() - boundingRect().height());
    }

    // Mueve la vista para que siempre siga a Lisa
    QGraphicsView* view = static_cast<QGraphicsView*>(juego->getVista());
    view->centerOn(this);  // Centra la vista en Lisa
}

// Detiene el movimiento del personaje
void Lisa::detener() {
    movingLeft = movingRight = movingUp = movingDown = false;
    spriteActual = spriteFrontal; // Restaurar al sprite frontal cuando se detiene
    update(); // Actualizar la representación gráfica
}

// Detecta colisiones y maneja interacción con objetos interactivos
bool Lisa::detectarColision(const QGraphicsItem* item) {
    if (collidesWithItem(item)) {
        auto* pista = dynamic_cast<const Pista*>(item);
        if (pista) {
            // Agrega la pista al inventario de Juego
            juego->getInventario()->agregarPista(const_cast<Pista*>(pista));
            std::cout << "Pista recogida: " << pista->obtenerDescripcion() << std::endl;
            return true;
        }

        auto* sospechoso = dynamic_cast<const Sospechoso*>(item);
        if (sospechoso) {
            std::cout << "Interacción con sospechoso: " << sospechoso->obtenerNombre() << std::endl;
            // Aquí podrías iniciar un diálogo o realizar una acción
            return true;
        }
    }
    return false;
}

// Método para actualizar Lisa en cada fase del ciclo del juego
void Lisa::advance(int phase) {
    if (!phase) return;
    mover(); // Actualiza el movimiento en cada ciclo
}

// Carga todos los sprites del personaje
void Lisa::cargarSprites() {
    spriteFrontal = QPixmap(":/sprites/lisa.png");
    spriteTrasero = QPixmap(":/sprites/espalda.png");
    spriteIzquierda = QPixmap(":/sprites/lado derecho.png");
    spriteDerecha = QPixmap(":/sprites/lado.png");

    if (spriteFrontal.isNull() || spriteTrasero.isNull() ||
        spriteIzquierda.isNull() || spriteDerecha.isNull()) {
        std::cerr << "Error: Uno o más sprites de Lisa no se cargaron correctamente." << std::endl;
    }
}

// Cambia el sprite actual según la dirección de movimiento
void Lisa::actualizarSprite(const QString& direction) {
    if (direction == "frontal") {
        spriteActual = spriteFrontal;
    } else if (direction == "trasero") {
        spriteActual = spriteTrasero;
    } else if (direction == "izquierda") {
        spriteActual = spriteIzquierda;
    } else if (direction == "derecha") {
        spriteActual = spriteDerecha;
    }
    update(); // Actualiza la representación gráfica
}
