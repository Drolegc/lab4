#ifndef SALA_H
#define SALA_H
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/headers/DtSala.h"
#include "../../ICollection/interfaces/IDictionary.h"
class Sala : public ICollectible {
    private:
        int numero;
        int capacidad;
    public:
        Sala(int numero, int capacidad);
        friend std::ostream& operator<<(std::ostream &o, Sala& df);
        int getNumero();
        int getCapacidad();
        static void listarSalas(IDictionary *salas);
        void setNumero(int numero);
        void setCapacidad(int capacidad);

        DtSala getSala();

        ~Sala();
};

#endif /* SALA_H */

