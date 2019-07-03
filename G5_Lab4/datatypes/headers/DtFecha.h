#ifndef DTFECHA_H
#define DTFECHA_H

#include <stdexcept>

class DtFecha {
    private:
        int dia;
        int mes;
        int anio;
        bool isValid();
    public:
        DtFecha(int dia, int mes, int anio);

        int getDia();
        int getMes();
        int getAnio();

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        bool operator>(const DtFecha *df) const;
        ~DtFecha();
};

#endif /* DTFECHA_H */

