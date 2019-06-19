#ifndef DTCINE_H
#define DTCINE_H
#include <iostream>
#include "../../datatypes/headers/DtDireccion.h"
class DtCine {
    public:
        DtCine(DtDireccion direccion, int numero);
        friend std::ostream& operator<<(std::ostream &o, DtCine* df);
        DtDireccion getDireccion();
        int getNumero();
        ~DtCine();
    private:
        DtDireccion direccion;
        int numero;

};

#endif /* DTCINE_H */

