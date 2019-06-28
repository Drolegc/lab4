#ifndef FUNCION_H
#define FUNCION_H

#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtHora.h"
#include "../../datatypes/headers/DtFuncion.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/List.h"
class Pelicula;

#include "Pelicula.h"

class Funcion : public ICollectible {
    private:
        int numero;
        DtFecha fecha;
        DtHora hora;
        ICollection* colReserva;
        Pelicula* pelicula;

    public:
        Funcion(int numero, DtFecha fecha, DtHora hora, Pelicula* pelicula);

        int getNumero();
        DtFecha getFecha();
        DtHora getHora();
        Pelicula* getPelicula();
        ICollection* getColReserva();

        bool tienePeli(Pelicula* p);
        void setNumero(int numero);
        void setFecha(DtFecha fecha);
        void setHora(DtHora hora);
        void setPelicula(Pelicula* pelicula);

        void listarFunciones(IDictionary* funciones);

        ~Funcion();
};

#endif /* FUNCION_H */

