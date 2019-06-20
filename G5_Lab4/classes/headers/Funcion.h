#ifndef FUNCION_H
#define FUNCION_H

#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtHora.h"
#include "../../datatypes/headers/DtFuncion.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"

#include "../../classes/headers/Pelicula.h"

class Funcion : public ICollectible {
    private:
        int numero;
        DtFecha fecha;
        DtHora hora;
        ICollection* Reserva;
        Pelicula* pelicula;
    public:
        Funcion(int numero, DtFecha fecha, DtHora hora);
        
        int getNumero();
        DtFecha getFecha();
        DtHora getHora();
        
        void setNumero(int numero);
        void setFecha(DtFecha fecha);
        void setHora(DtHora hora);

//        Funcion altaFuncion(DtHora hora, DtFecha fecha);
//        bool tienePeli(ICollectible* p);
//        ICollectible* obtenerFuncion();
//        ICollection* obtenerFunciones();
//        void eliminarFunciones();
        bool tienePeli(Pelicula* p);
        
        ~Funcion();
};

#endif /* FUNCION_H */

