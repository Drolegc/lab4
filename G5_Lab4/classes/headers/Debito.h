#ifndef DEBITO_H
#define DEBITO_H

#include <string>
#include "Reserva.h"

class Debito : public Reserva {
    private:
        std::string bancoEmisor;
    public:
        Debito(int asientos, int costoTotal, std::string bancoEmisor);
        
        std::string getBancoEmisor();
        
        void setBancoEmisor(std::string bancoEmisor);
        
        void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion);
        
        ~Debito();
};

#endif /* DEBITO_H */

