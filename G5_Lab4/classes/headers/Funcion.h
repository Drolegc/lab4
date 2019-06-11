#ifndef FUNCION_H
#define FUNCION_H

#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtHora.h"
#include "../../datatypes/headers/DtFuncion.h"

class Funcion {
    private:
        int numero;
        DtFecha fecha;
        DtHora hora;
    public:
        Funcion(int numero, DtFecha fecha, DtHora hora);
        
        int getNumero();
        DtFecha getFecha();
        DtHora getHora();
        
        void setNumero(int numero);
        void setFecha(DtFecha fecha);
        void setHora(DtHora hora);
        
        DtFuncion getFuncion();
        void eliminarFuncion(int numero);
        
        ~Funcion();
};

#endif /* FUNCION_H */

