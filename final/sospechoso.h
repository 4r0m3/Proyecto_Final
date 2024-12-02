#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include <string>
#include <map>
#include <vector>
#include <QGraphicsPixmapItem>
#include "ObjetoInteractivo.h"

class Sospechoso : public ObjetoInteractivo {
private:
    bool entrevistado;              ///< Indica si el sospechoso ha sido entrevistado
    QGraphicsPixmapItem* sprite;    ///< Sprite del sospechoso
    std::map<int, std::string> respuestas; ///< Respuestas del sospechoso por pregunta

public:
    // Constructor
    explicit Sospechoso(const std::string& nombre);

    // Métodos básicos
    std::string obtenerNombre() const;    ///< Devuelve el nombre del sospechoso
    bool haSidoEntrevistado() const;      ///< Verifica si el sospechoso ha sido entrevistado
    void marcarEntrevistado();            ///< Marca al sospechoso como entrevistado

    // Métodos para asignar respuestas
    void agregarRespuesta(int idPregunta, const std::string& respuesta); ///< Asigna respuestas al sospechoso
    std::string obtenerRespuesta(int idPregunta) const; ///< Obtiene la respuesta para una pregunta específica

    // Métodos para el sprite
    void setSprite(const QString& rutaImagen);   ///< Asigna el sprite del sospechoso
    QGraphicsPixmapItem* getSprite() const;      ///< Obtiene el sprite del sospechoso

    // Método estático para crear sospechosos según el nivel
    static std::vector<Sospechoso*> crearSospechosos(int nivelID, QGraphicsScene* escena);

    // Métodos virtuales heredados
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    void interactuar() override;
};

#endif // SOSPECHOSO_H
