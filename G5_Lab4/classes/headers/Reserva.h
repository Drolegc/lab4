#ifndef RESERVA_H
#define RESERVA_H

#include "../../ICollection/interfaces/ICollectible.h"
class Funcion;
#include "Funcion.h"
class Reserva : public ICollectible {
    protected:
        int asientos;
        int costoTotal;
        Funcion* f;
    public:
        Reserva(int asientos, int costoTotal,Funcion* f);

        int getAsientos();
        int getCostoTotal();

        void setAsientos(int asientos);
        void setCostoTotal(int costoTotal);

        void eliminarReservas();

        virtual ~Reserva();
};

#endif /* RESERVA_H */

