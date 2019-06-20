#ifndef DTCINE_H
#define DTCINE_H

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/List.h"
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
        IDictionary* salas;
        int numero;

};
#endif /* DTCINE_H */

