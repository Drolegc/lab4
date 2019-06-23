#ifndef DTFUNCION_H
#define DTFUNCION_H

#include <iostream>
#include "DtFecha.h"
#include "DtHora.h"
#include "../../classes/headers/Pelicula.h"
#include "../../ICollection/interfaces/ICollectible.h"

class DtFuncion:public ICollectible  {
    private:
        int numero;
        DtFecha fecha;
        DtHora hora;
        Pelicula* pelicula;
    public:
        DtFuncion(int numero, DtFecha fecha, DtHora hora, Pelicula* pelicula);
        
        int getNumero();
        DtFecha getFecha();
        DtHora getHora();
        Pelicula* getPelicula();
        
        void setNumero(int numero);
        void setFecha(DtFecha fecha);
        void setHora(DtHora hora);
        void setPelicula(Pelicula* pelicula);
        
        friend std::ostream& operator<<(std::ostream &o, DtFuncion* dtF);
};

#endif /* DTFUNCION_H */
