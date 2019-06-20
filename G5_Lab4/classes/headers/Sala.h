#ifndef SALA_H
#define SALA_H
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/headers/DtSala.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../classes/headers/Funcion.h"
#include "../../classes/headers/Pelicula.h"
class Sala : public ICollectible {
    private:
        int numero;
        int capacidad;
        Funcion * funcion;
    public:
        Sala(int numero, int capacidad);
        friend std::ostream& operator<<(std::ostream &o, Sala& df);
        int getNumero();
        int getCapacidad();
        static void listarSalas(IDictionary *salas);
        void setNumero(int numero);
        void setCapacidad(int capacidad);
        DtFuncion* getDtFuncion(Pelicula* p);
        Funcion* getFuncion();

        DtSala getSala();

        ~Sala();
};

#endif /* SALA_H */

