#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>

class DtDireccion {
    private:
        std::string calle;
        int numero;
        std::string ciudad;
    public:
        DtDireccion(std::string calle, int numero, std::string ciudad);
        
        std::string getCalle();
        int getNumero();
        std::string getCiudad();
        
        void setCalle(std::string calle);
        void setNumero(int numero);
        void setCiudad(std::string ciudad);
        
        virtual ~DtDireccion();
};

#endif /* DTDIRECCION_H */

