#ifndef SALA_H
#define SALA_H

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/headers/DtSala.h"

class Sala : public ICollectible {
    private:
        int numero;
        int capacidad;
    public:
        Sala(int numero, int capacidad);
        
        int getNumero();
        int getCapacidad();
        
        void setNumero(int numero);
        void setCapacidad(int capacidad);
        
        DtSala getSala();
        
        ~Sala();
};

#endif /* SALA_H */

