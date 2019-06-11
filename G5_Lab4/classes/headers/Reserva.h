#ifndef RESERVA_H
#define RESERVA_H

class Reserva : ISistema{
    protected:
        int asientos;
        int costoTotal;
    public:
        Reserva(int asientos, int costoTotal);
        
        int getAsientos();
        int getCostoTotal();
        
        void setAsientos(int asientos);
        void setCostoTotal(int costoTotal);
        
        ~Reserva();
};

#endif /* RESERVA_H */

