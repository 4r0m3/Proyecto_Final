#ifndef NIVEL_H
#define NIVEL_H

#include <string>

using namespace std;

/**
 * @brief Clase abstracta que representa un nivel genÃ©rico del juego
 * @details Define los mÃ©todos base para los niveles especÃ­ficos
 */
class Nivel {
public:
    virtual ~Nivel() = default;

    /**
     * @brief MÃ©todo para iniciar el nivel (virtual puro)
     */
    virtual void iniciarNivel() = 0;

    /**
     * @brief MÃ©todo para finalizar el nivel (virtual puro)
     */
    virtual void terminarNivel() = 0;

protected:
    string objetivo; ///< DescripciÃ³n del objetivo del nivel
};

#endif // NIVEL_H
