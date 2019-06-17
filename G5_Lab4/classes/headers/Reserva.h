#ifndef RESERVA_H
#define RESERVA_H

#include "../../ICollection/interfaces/ICollectible.h"

class Reserva : public ICollectible {
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
        
        virtual ~Reserva();
};

#endif /* RESERVA_H */

