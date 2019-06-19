#ifndef DTDIRECCION_H
#define DTDIRECCION_H
#include <iostream>

#include <string>

class DtDireccion {
    private:
        std::string calle;
        int numero;
        std::string ciudad;
    public:
        DtDireccion(std::string calle, int numero, std::string ciudad);
        DtDireccion();
        std::string getCalle();
        int getNumero();
        std::string getCiudad();
        friend std::ostream& operator<<(std::ostream &o, DtDireccion& df);
        void setCalle(std::string calle);
        void setNumero(int numero);
        void setCiudad(std::string ciudad);
        
        virtual ~DtDireccion();
};

#endif /* DTDIRECCION_H */

