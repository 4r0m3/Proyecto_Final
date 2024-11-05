#include "Inventario.h"

using namespace std;

void Inventario::agregarPista(const Pista& pista){
    pistas.push_back(pista);
}
const vector<Pista>& Inventario::obtenerPistas()const{
    return pistas;
}
