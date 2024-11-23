#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPushButton>
#include <QVBoxLayout>
#include "Juego.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent* event);

private slots:
    void cambiarNivel1();
    void cambiarNivel2();
    void cambiarNivel3();

private:
    Ui::MainWindow *ui;
    QGraphicsView *vista;

    QGraphicsScene *scene;
    QGraphicsRectItem* Personaje;
    QGraphicsRectItem* inventario;
    QGraphicsRectItem* dialogos;
    juego* juego; ///< Instancia del controlador lÃ³gico del juego
    QPushButton* botonNivel1; ///< BotÃ³n para cargar el Nivel 1
    QPushButton* botonNivel2; ///< BotÃ³n para cargar el Nivel 2
    QPushButton* botonNivel3; ///< BotÃ³n para cargar el Nivel 3
    QVBoxLayout* layout; ///< Layout principal para los botones y la vista

    int cont_I;

};
#endif // MAINWINDOW_H
