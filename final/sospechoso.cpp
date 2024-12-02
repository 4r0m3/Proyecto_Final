#include "Sospechoso.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>

// Constructor
Sospechoso::Sospechoso(const std::string& nombre)
    : ObjetoInteractivo(nombre), entrevistado(false), sprite(nullptr) {}

// Devuelve el nombre del sospechoso
std::string Sospechoso::obtenerNombre() const {
    return getNombre(); // Usa el método heredado de ObjetoInteractivo
}

// Verifica si el sospechoso ha sido entrevistado
bool Sospechoso::haSidoEntrevistado() const {
    return entrevistado;
}

// Marca al sospechoso como entrevistado
void Sospechoso::marcarEntrevistado() {
    entrevistado = true;
}

// Asigna una respuesta a una pregunta específica
void Sospechoso::agregarRespuesta(int idPregunta, const std::string& respuesta) {
    respuestas[idPregunta] = respuesta;
}

// Obtiene la respuesta a una pregunta específica
std::string Sospechoso::obtenerRespuesta(int idPregunta) const {
    auto it = respuestas.find(idPregunta);
    if (it != respuestas.end()) {
        return it->second;
    }
    return "Respuesta no disponible.";
}

// Asigna el sprite al sospechoso
void Sospechoso::setSprite(const QString& rutaImagen) {
    if (!sprite) {
        sprite = new QGraphicsPixmapItem();
    }
    QPixmap pixmap(rutaImagen);
    sprite->setPixmap(pixmap);
}

// Obtiene el sprite del sospechoso
QGraphicsPixmapItem* Sospechoso::getSprite() const {
    return sprite;
}

// Crea los sospechosos según el nivel y los agrega a la escena
std::vector<Sospechoso*> Sospechoso::crearSospechosos(int nivelID, QGraphicsScene* escena) {
    std::vector<Sospechoso*> sospechosos;

    switch (nivelID) {
    case 1: // Nivel 1: Escena del crimen
    {
        Sospechoso* moe = new Sospechoso("Moe Szyslak");
        moe->setSprite(":/sprites/moe.png");
        moe->agregarRespuesta(1, "Burns me ha arruinado los negocios.");
        moe->agregarRespuesta(2, "No estoy diciendo que lo hice, pero podría estar enfadado.");
        escena->addItem(moe->getSprite());
        moe->getSprite()->setPos(100, 200);
        sospechosos.push_back(moe);

        Sospechoso* barney = new Sospechoso("Barney Gumble");
        barney->setSprite(":/sprites/barney.png");
        barney->agregarRespuesta(1, "El Sr. Burns siempre me molesta en Moe's.");
        barney->agregarRespuesta(2, "Esa sombra arruinó mi bar.");
        escena->addItem(barney->getSprite());
        barney->getSprite()->setPos(300, 200);
        sospechosos.push_back(barney);
    }
    break;

    case 2: // Nivel 2: Entrevista a sospechosos
    {
        Sospechoso* marge = new Sospechoso("Marge Simpson");
        marge->setSprite(":/sprites/marge.png");
        marge->agregarRespuesta(1, "No puedo creer que alguien intente dañar al Sr. Burns.");
        marge->agregarRespuesta(2, "Siempre intento mantener la paz en mi familia.");
        escena->addItem(marge->getSprite());
        marge->getSprite()->setPos(100, 300);
        sospechosos.push_back(marge);

        Sospechoso* skinner = new Sospechoso("Principal Skinner");
        skinner->setSprite(":/sprites/skinner.png");
        skinner->agregarRespuesta(1, "El petróleo robado nos costó mucho en la escuela.");
        skinner->agregarRespuesta(2, "Es un hombre despiadado, pero no recurriría a la violencia.");
        escena->addItem(skinner->getSprite());
        skinner->getSprite()->setPos(300, 300);
        sospechosos.push_back(skinner);
    }
    break;

    case 3: // Nivel 3: Resolución del caso
    {
        Sospechoso* smithers = new Sospechoso("Waylon Smithers");
        smithers->setSprite(":/sprites/smithers.png");
        smithers->agregarRespuesta(1, "Siempre he sido leal al Sr. Burns.");
        smithers->agregarRespuesta(2, "Pero últimamente, cruzó demasiados límites.");
        escena->addItem(smithers->getSprite());
        smithers->getSprite()->setPos(100, 400);
        sospechosos.push_back(smithers);

        Sospechoso* bart = new Sospechoso("Bart Simpson");
        bart->setSprite(":/sprites/bart.png");
        bart->agregarRespuesta(1, "El viejo Burns es un tipo desagradable.");
        bart->agregarRespuesta(2, "Dispararle es demasiado para mí.");
        escena->addItem(bart->getSprite());
        bart->getSprite()->setPos(300, 400);
        sospechosos.push_back(bart);
    }
    break;

    default:
        std::cerr << "Nivel no válido: " << nivelID << std::endl;
        break;
    }

    return sospechosos;
}

// Implementación del método 'paint' (para QGraphicsItem)
void Sospechoso::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    if (sprite) {
        painter->drawPixmap(0, 0, sprite->pixmap());
    }
}

// Implementación del método 'interactuar' (acción al interactuar con el sospechoso)
void Sospechoso::interactuar() {
    std::cout << "Interacción con " << getNombre() << std::endl;
    // Aquí se podría implementar la lógica de diálogo o cualquier otra acción
}
