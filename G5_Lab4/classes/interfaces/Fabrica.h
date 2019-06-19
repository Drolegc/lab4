#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>
#include "ISistema.h"
#include "ControladorSistema.h"

class Fabrica {
    private:
        static ISistema* controladorSistema;
        Fabrica();
    public:
        static ISistema* getISistema();
};

#endif /* FABRICA_H */

