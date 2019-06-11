#ifndef CINE_H
#define CINE_H

#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtCine.h"

class Cine : ISistema{
    private:
        int numero;
        DtDireccion direccion;
    public:
        Cine(int numero, DtDireccion direccion);
        
        int getNumero();
        DtDireccion getDireccion();
        
        void setNumero(int numero);
        void setDireccion(DtDireccion direccion);
        
        DtCine listarCines();
        
        ~Cine();
};

#endif /* CINE_H */

