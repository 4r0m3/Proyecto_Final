#include "Sospechoso.h"

using namespace std;

Sospechoso::Sospechoso(const string& nombre, const string& descripcion)
    : nombre(nombre), descripcion(descripcion){
    //agrega respuestas
    respuestas.push_back("si, fui yo");
    respuestas.push_back("no fui yo") ;
}
string Sospechoso::darRespuesta(){
    //por simplicidad, devuelve la primera respuesta
    return respuestas.empty() ? "" : respuestas[0];
}
