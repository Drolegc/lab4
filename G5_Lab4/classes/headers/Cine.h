#ifndef CINE_H
#define CINE_H

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtCine.h"
#include "../../ICollection/StringKey.h"
#include "../../classes/headers/Sala.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../classes/headers/Pelicula.h"
class DtCine;

class Cine :public ICollectible{
    private:
        int numero;
        DtDireccion direccion;
        IDictionary* dicSalas;
        IDictionary* dicPeliculas;
    public:
        Cine(DtCine *cine);
        Cine(std::string calle,int num,std::string ciudad,int id);
        static void listarCines(IDictionary* cine);
        static void CinesConPeli(ICollection* c);
        int getNumero();
        DtDireccion getDireccion();
        IDictionary* getSalas();
        ICollection* getFunciones(Pelicula* p);
        Funcion* getFuncion(int id_funcion);

        void setNumero(int numero);
        void setDireccion(DtDireccion direccion);

        void agregarSala(int capacidad);
        //Leandro: tienePeli para el caso de uso CrearReserva
        bool tienePeli(StringKey* clave);
        void addPelicula(Pelicula* p);
        
        ~Cine();
};

#endif  /* CINE_H */

