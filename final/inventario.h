#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Pista.h"
#include <string>
using namespace std;

/**
 * @brief Clase que representa el inventario de pistas de Lisa
 * @details Almacena y gestiona las pistas recolectadas en el juego
 */
class Inventario {
public:
    Inventario();

    /**
     * @brief Agrega una pista al inventario
     * @param pista Puntero a la pista que se agregarÃ¡ al inventario
     */
    void agregarPista(Pista* pista);

    /**
     * @brief Muestra las pistas almacenadas en el inventario
     */
    void mostrarInventario() const;

    /**
     * @brief Busca una pista en el inventario por su descripciÃ³n
     * @param descripcion DescripciÃ³n de la pista a buscar
     * @return Puntero a la pista encontrada o nullptr si no existe
     */
    Pista* buscarPista(const string& descripcion) const;

private:
    vector<Pista*> pistas; ///< Vector dinÃ¡mico que almacena las pistas recolectadas
};

#endif // INVENTARIO_H
