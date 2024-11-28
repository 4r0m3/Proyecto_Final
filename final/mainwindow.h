#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include "juego.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase MainWindow
     * @param parent Puntero al widget padre (por defecto nullptr)
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase MainWindow
     */
    ~MainWindow();

private slots:
    /**
     * @brief Cambia a la escena de selección de niveles
     */
    void irSeleccionNiveles();

    /**
     * @brief Cambia a la escena del nivel 1
     */
    void cambiarNivel1();

    /**
     * @brief Cambia a la escena del nivel 2
     */
    void cambiarNivel2();

    /**
     * @brief Cambia a la escena del nivel 3
     */
    void cambiarNivel3();

private:
    QGraphicsView* vista; ///< Vista gráfica para mostrar las escenas
    QGraphicsScene* escenaMenu; ///< Escena del menú principal
    QGraphicsScene* escenaSeleccionNiveles; ///< Escena de selección de niveles
    juego* juego; ///< Instancia del juego
};

#endif // MAINWINDOW_H
