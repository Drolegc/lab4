#ifndef SALA_H
#define SALA_H

#include "../../datatypes/headers/DtSala.h"

class Sala {
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

