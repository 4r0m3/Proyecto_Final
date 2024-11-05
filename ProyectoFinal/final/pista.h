#ifndef PISTA_H
#define PISTA_H
#include <string>
using namespace std;
class Pista {
public:
    Pista(const string& descripcion);
    void marcarComoClave();
    bool esClave() const;
private:
    string descripcion;
    bool clave;
};

#endif // PISTA_H
