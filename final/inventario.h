#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Pista.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Clase que gestiona el inventario de pistas en el juego
 */
class Inventario {
private:
    vector<Pista*> pistas; ///< Almacena las pistas recolectadas

public:
    /**
     * @brief Constructor por defecto
     */
    Inventario();

    /**
     * @brief Agrega una pista al inventario
     * @param pista Puntero a la pista que se va a agregar
     */
    void agregarPista(Pista* pista);

    /**
     * @brief Verifica si todas las pistas clave han sido recolectadas
     * @return true si todas las pistas clave están recolectadas, false en caso contrario
     */
    bool todasLasPistasClaveRecolectadas() const;

    /**
     * @brief Busca una pista por su descripción
     * @param descripcion Descripción de la pista a buscar
     * @return Puntero a la pista encontrada o nullptr si no existe
     */
    Pista* buscarPista(const string& descripcion) const;

    /**
     * @brief Devuelve el número de pistas recolectadas
     * @return Cantidad de pistas en el inventario
     */
    int obtenerCantidadPistas() const;
};

#endif // INVENTARIO_H
