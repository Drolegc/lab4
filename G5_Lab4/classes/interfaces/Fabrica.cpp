#include "Fabrica.h"

Fabrica* Fabrica::instance = 0;

Fabrica* Fabrica::getInstance() {
    if(instance == 0) {
        instance = new Fabrica();
    }
    return instance;
}

Fabrica::Fabrica() {
    
}