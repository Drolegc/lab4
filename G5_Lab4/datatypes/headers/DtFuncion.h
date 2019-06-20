#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtHora.h"
#include "../../ICollection/interfaces/ICollectible.h"

class DtFuncion : public ICollectible{
private:
    int numero;
    DtFecha fecha;
    DtHora hora;

public:
    DtFuncion(int numero, DtFecha fecha, DtHora hora);
    int getNumero();
    DtFecha getFecha();
    DtHora getHora();
};

#endif /* DTFUNCION_H */
