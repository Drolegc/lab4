#ifndef DTHORA_H
#define DTHORA_H

class DtHora {
    private:
        int hora;
        int minutos;
    public:
        DtHora(int hora, int minutos);
        
        int getHora();
        int getMinutos();
        
        void setHora(int hora);
        void setMinutos(int minutos);
        
        ~DtHora();
};

#endif /* DTHORA_H */

