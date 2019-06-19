#ifndef CINE_H
#define CINE_H

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtCine.h"
#include "../../ICollection/StringKey.h"

class Cine : public ICollectible {
    private:
        int numero;
        DtDireccion direccion;
        IDictionary* dicSalas;
        IDictionary* dicPeliculas;
    public:
        Cine(int numero, DtDireccion direccion);
        
        int getNumero();
        DtDireccion getDireccion();
        
        void setNumero(int numero);
        void setDireccion(DtDireccion direccion);
        
        void agregarSala(int capacidad);
        //Leandro: tienePeli para el caso de uso CrearReserva
        bool tienePeli(StringKey* clave);
        
        ~Cine();
};

#endif /* CINE_H */

