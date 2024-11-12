#include "nivel.h"
#include <iostream>

using namespace std;

/**
 * @brief Clase concreta que hereda de Nivel y representa un nivel especÃ­fico
 */
class NivelConcreto : public Nivel {
public:
    /**
     * @brief Constructor de NivelConcreto
     * @param objetivo La descripciÃ³n del objetivo del nivel
     */
    NivelConcreto(const string& objetivo) {
        this->objetivo = objetivo;
    }

    /**
     * @brief MÃ©todo para iniciar el nivel
     */
    void iniciarNivel() override {
        cout << "Iniciando el nivel con el objetivo: " << objetivo << endl;
    }

    /**
     * @brief MÃ©todo para finalizar el nivel
     */
    void terminarNivel() override {
        cout << "Terminando el nivel con el objetivo: " << objetivo << endl;
    }
};

int main() {
    // Crear un objeto de la clase NivelConcreto
    NivelConcreto miNivel("Recoge todas las estrellas");

    // Iniciar y finalizar el nivel
    miNivel.iniciarNivel();
    miNivel.terminarNivel();

    return 0;
}
