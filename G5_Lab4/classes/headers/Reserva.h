#ifndef RESERVA_H
#define RESERVA_H

#include "../../ICollection/interfaces/ICollection.h"

class Reserva : public ICollection {
    protected:
        int asientos;
        int costoTotal;
    public:
        Reserva(int asientos, int costoTotal);
        
        int getAsientos();
        int getCostoTotal();
        
        void setAsientos(int asientos);
        void setCostoTotal(int costoTotal);
        
        void eliminarReservas();
        
        ~Reserva();
};

#endif /* RESERVA_H */

