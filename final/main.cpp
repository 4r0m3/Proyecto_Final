#include "mainwindow.h"

#include "Juego.h"
#include "Pista.h"
#include "Sospechoso.h"
#include "Dialogo.h"
#include "Inventario.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    juego game;
    game.iniciarJuego();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
