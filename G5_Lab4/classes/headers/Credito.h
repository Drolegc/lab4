#ifndef CREDITO_H
#define CREDITO_H

#include <string>
#include "../headers/Reserva.h"

class Credito : public Reserva {
    private:
        int porcentajeDescuento;
        std::string financiera;
    public:
        Credito(int asientos, int costoTotal, int porcentajeDescuento, std::string financiera);
        
        int getPorcentajeDescuento();
        std::string getFinanciera();
        
        void setPorcentajeDescuento(int porcentajeDescuento);
        void setFinanciera(std::string financiera);
        
        void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion);
        
        ~Credito();
};

#endif /* CREDITO_H */

