#ifndef NIVELRESOLUCION_H
#define NIVELRESOLUCION_H

#include "Nivel.h"
#include "Sospechoso.h"
#include "Juego.h"
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QObject>

class NivelResolucion : public Nivel {
private:
    vector<Sospechoso*> sospechosos;  ///< Lista de sospechosos
    QPushButton* botonSospechoso[6];  ///< Botones para acusar a los sospechosos
    QGraphicsTextItem* textoMensaje; ///< Mensaje de revelación

public:
    /**
     * @brief Constructor de NivelResolucion
     * @param inventario Referencia al inventario compartido del juego
     * @param juego Referencia al juego
     */
    NivelResolucion(Inventario* inventario, juego* juego);

    /**
     * @brief Inicia el nivel de resolución
     * @param escena Escena gráfica del nivel
     */
    void iniciarNivel(QGraphicsScene* escena) override;

    /**
     * @brief Finaliza el nivel de resolución
     */
    void terminarNivel() override;

    /**
     * @brief Actualiza el nivel, mostrando los botones de acusación
     */
    void actualizar() override;

    /**
     * @brief Responde a la acusación de Lisa
     */
    void acusarSospechoso(int indice);

    /**
     * @brief Crea los botones de acusación
     */
    void crearBotonesAcusacion(QGraphicsScene* escena);
};

#endif // NIVELRESOLUCION_H


