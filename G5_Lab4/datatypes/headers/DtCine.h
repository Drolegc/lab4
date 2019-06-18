#ifndef DTCINE_H
#define DTCINE_H

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../datatypes/headers/DtDireccion.h"

class DtCine {
    private:
        int numero;
        DtDireccion direccion;
        IDictionary* salas;
    public:
        DtCine(int numero, DtDireccion direccion);
        
        int getNumero();
        DtDireccion getDireccion();
        
        void setNumero(int numero);
        void setDireccion(DtDireccion direccion);
        
        void agregarSala(int capacidad);
        
        ~DtCine();
};
#endif /* DTCINE_H */

