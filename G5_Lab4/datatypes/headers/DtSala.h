#ifndef DTSALA_H
#define DTSALA_H
#include <iostream>

class DtSala {
    private:
        int numero;
        int capacidad;
    public:
        DtSala(int numero, int capacidad);
        friend std::ostream& operator<<(std::ostream &o, DtSala* df);
        int getNumero();
        int getCapacidad();
        ~DtSala();
};

#endif /* DTSALA_H */

