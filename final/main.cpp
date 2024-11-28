#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    // Inicializar la aplicación Qt
    QApplication app(argc, argv);

    // Crear y mostrar la ventana principal
    MainWindow mainWindow;
    mainWindow.show();

    // Ejecutar el bucle principal de eventos
    return app.exec();
}

