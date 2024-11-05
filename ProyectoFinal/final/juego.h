#ifndef JUEGO_H
#define JUEGO_H

class Juego {
public:
    Juego(); //constrcutor
    void iniciarJuego(); //inicia el juego
    void terminarJuego(); // termina el juego
private:
    int nivelActual; // variable para el seguimiento del nivel
};

#endif // JUEGO_H
