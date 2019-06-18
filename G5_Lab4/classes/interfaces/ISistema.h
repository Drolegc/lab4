#ifndef ISISTEMA_H
#define ISISTEMA_H

#include "../../ICollection/interfaces/ICollection.h"
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtHora.h"
#include "../../datatypes/headers/DtPelicula.h"

class ISistema {
    public:
        ISistema();
        virtual void altaCine(DtDireccion direccion) = 0;
//        virtual void altaFuncion(DtFecha fecha, DtHora hora);
//        virtual void eliminarPelicula(std::string titulo);
//        virtual void iniciarSesion(std::string nickname, std::string contrasenia);
//        virtual ICollection* listarCines();
//        virtual ICollection* listarPeliculas();
//        virtual void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion);
//        virtual void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion);
       virtual DtPelicula seleccionarPelicula(std::string titulo) = 0;
//        virtual DtPelicula verInfoAdicional();
        virtual ~ISistema();
};

#endif /* ISISTEMA_H */

