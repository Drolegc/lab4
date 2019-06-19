#ifndef CINE_H
#define CINE_H
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtCine.h"
#include "../../classes/headers/Sala.h"
#include "../../ICollection/interfaces/ICollectible.h"
class DtCine;
class Cine :public ICollectible{
    private:
        int numero;
        DtDireccion direccion;
        IDictionary* salas;
    public:
        Cine(DtCine *cine);
        static void listarCines(IDictionary* cine);
        int getNumero();
        DtDireccion getDireccion();
        IDictionary* getSalas();
        void setNumero(int numero);
        void setDireccion(DtDireccion direccion);

        void agregarSala(int capacidad);

        ~Cine();
};

#endif  /* CINE_H */

