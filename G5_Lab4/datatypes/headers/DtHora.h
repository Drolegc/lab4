#ifndef DTHORA_H
#define DTHORA_H

#include <stdexcept>

class DtHora {
    private:
        int hora;
        int minutos;
        bool isValid();
    public:
        DtHora(int hora, int minutos);
        
        int getHora();
        int getMinutos();
        
        void setHora(int hora);
        void setMinutos(int minutos);
        
        ~DtHora();
};

#endif /* DTHORA_H */

