#ifndef PUNTAJES_H
#define PUNTAJES_H
#include <iostream>
#include "../../ICollection/IntKey.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/interfaces/ICollectible.h"

#include "Usuario.h"
class Puntajes :public ICollectible{
    private:
        int puntaje;
        Usuario * usuario;
    public:
        Puntajes(int numero, Usuario *sesion);
        int getPuntaje();
        Usuario* getUsuario();
        void setUsuario();
        ~Puntajes();
};

#endif /* PUNTAJES_H */

