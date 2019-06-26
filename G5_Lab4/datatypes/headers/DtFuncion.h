#ifndef DTFUNCION_H
#define DTFUNCION_H

#include <iostream>
#include "DtFecha.h"
#include "DtHora.h"
#include "../../classes/headers/Pelicula.h"

class Pelicula;

class DtFuncion {
    private:
        int numero;
        DtFecha fecha;
        DtHora hora;
//        Pelicula* pelicula;
        std::string tituloPelicula;
    public:
//        DtFuncion(int numero, DtFecha fecha, DtHora hora, Pelicula* pelicula);
        DtFuncion(int numero, DtFecha fecha, DtHora hora, std::string tituloPelicula);
        
        int getNumero();
        DtFecha getFecha();
        DtHora getHora();
//        Pelicula* getPelicula();
        std::string getTituloPelicula();
        
        void setNumero(int numero);
        void setFecha(DtFecha fecha);
        void setHora(DtHora hora);
//        void setPelicula(Pelicula* pelicula);
        void setTituloPelicula(std::string titulo);
        
        friend std::ostream& operator<<(std::ostream &o, DtFuncion* dtF);
};

#endif /* DTFUNCION_H */

