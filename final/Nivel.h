#ifndef NIVEL_H
#define NIVEL_H

#include <string>
using namespace std;

class Nivel {
public:
    virtual void iniciarNivel() = 0;
    virtual void terminarNivel() = 0;
    virtual ~Nivel() = default;

protected:
    string objetivo;
};

#endif // NIVEL_H


