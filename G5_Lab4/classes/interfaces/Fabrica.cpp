#include "Fabrica.h"

ISistema* Fabrica::controladorSistema = 0;

ISistema* Fabrica::getISistema() {
    if(controladorSistema == NULL) {
        controladorSistema = new ControladorSistema();
    }
    return controladorSistema;
}

Fabrica::Fabrica() {
    
}