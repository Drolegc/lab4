#ifndef CINE_H
#define CINE_H

#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtCine.h"
#include "../../ICollection/interfaces/ICollection.h"

class Cine {
    private:
        int numero;
        DtDireccion direccion;
    public:
        Cine(int numero, DtDireccion direccion);
        
        int getNumero();
        DtDireccion getDireccion();
        
        void setNumero(int numero);
        void setDireccion(DtDireccion direccion);
        
        ICollection* listarCines();
        
        ~Cine();
};

#endif /* CINE_H */

