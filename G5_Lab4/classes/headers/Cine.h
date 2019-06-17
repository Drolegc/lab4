#ifndef CINE_H
#define CINE_H

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtCine.h"

class Cine {
    private:
        int numero;
        DtDireccion direccion;
        IDictionary* salas;
    public:
        Cine(int numero, DtDireccion direccion);
        
        int getNumero();
        DtDireccion getDireccion();
        
        void setNumero(int numero);
        void setDireccion(DtDireccion direccion);
        
        void agregarSala(int capacidad);
        
        ~Cine();
};

#endif /* CINE_H */

