#ifndef OBJETOINTERACTIVO_H
#define OBJETOINTERACTIVO_H

#include <string>

class ObjetoInteractivo {
public:
    ObjetoInteractivo(std::string nombre);
    virtual void interactuar() = 0; // MÃ©todo virtual puro, para que cada objeto defina su interacciÃ³n especÃ­fica
    virtual ~ObjetoInteractivo() = default; // Destructor virtual para asegurar eliminaciÃ³n correcta en herencia

protected:
    std::string nombre; // Nombre del objeto interactivo
};

#endif // OBJETOINTERACTIVO_H
