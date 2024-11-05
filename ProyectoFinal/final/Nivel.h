#ifndef NIVEL_H
#define NIVEL_H

class Nivel {
public:
    virtual void iniciarNivel() = 0;   // MÃ©todo abstracto para iniciar el nivel
    virtual void terminarNivel() = 0;  // MÃ©todo abstracto para finalizar el nivel
};

#endif // NIVEL_H

