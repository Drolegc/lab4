#ifndef ISISTEMA_H
#define ISISTEMA_H

#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtHora.h"
#include "../../datatypes/headers/DtPelicula.h"
#include "../../classes/headers/Pelicula.h"

class ISistema {
    public:
        ISistema();
        virtual void altaFuncion(DtFecha fecha, DtHora hora) = 0;
        virtual void altaPelicula(DtPelicula datos) = 0;
        virtual void altaCine(DtDireccion direccion) = 0;
        virtual void comentarPelicula() = 0;
//        virtual void eliminarPelicula(std::string titulo);
//        virtual void iniciarSesion(std::string nickname, std::string contrasenia);
//        virtual ICollection* listarCines();
        virtual void listarPeliculas() = 0;
//        virtual void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion);
//        virtual void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion);
       virtual DtPelicula seleccionarPelicula(std::string titulo) = 0;
       virtual ICollection* verInfoAdicional(DtPelicula p) = 0;
//        virtual DtPelicula verInfoAdicional();
        virtual ~ISistema();
        virtual void listarCines() = 0;
        virtual ICollection* SeleccionarCine(int numCine,std::string titulo) = 0;
        virtual void pagoDebito(int asientos,std::string banco,int funcion) = 0;

};

#endif /* ISISTEMA_H */

