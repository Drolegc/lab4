#ifndef ISISTEMA_H
#define ISISTEMA_H

#include "../../ICollection/interfaces/ICollection.h"

class ISistema {
    public:
        virtual void altaFuncion(DtFecha fecha, DtHora hora);
        virtual DtPelicula verInfoAdicional() = 0;
        virtual void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion) = 0;
        virtual void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion) = 0;
        virtual void eliminarPelicula(std::string titulo) = 0;
        virtual ICollection* listarPeliculas() = 0;
        virtual void iniciarSesion(std::string nickname, std::string contrasenia) = 0;
        virtual ICollection* listarCines() = 0;
};

#endif /* ISISTEMA_H */

