#ifndef SALA_H
#define SALA_H
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/headers/DtSala.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../classes/headers/Funcion.h"
#include "../../datatypes/headers/DtFuncion.h"
class Sala : public ICollectible {
    private:
        int numero;
        int capacidad;
        IDictionary* dicFunciones;
    public:
        Sala(int numero, int capacidad);
        friend std::ostream& operator<<(std::ostream &o, Sala& df);
        int getNumero();
        int getCapacidad();
        IDictionary* getDicFunciones();
        static void listarSalas(IDictionary *salas);
        void setNumero(int numero);
        void setCapacidad(int capacidad);
        DtFuncion* getDtFuncion(Pelicula* p);
        Funcion* getFuncion(int id);

        void getFunciones();
        DtSala getSala();

        ~Sala();
};

#endif /* SALA_H */

