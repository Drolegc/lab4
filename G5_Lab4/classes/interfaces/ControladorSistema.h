#ifndef CONTROLADORSISTEMA_H
#define CONTROLADORSISTEMA_H

#include "../headers/Pelicula.h"
#include "../headers/Cine.h"
#include "../headers/Credito.h"
#include "../headers/Debito.h"
#include "../headers/Usuario.h"
#include "../../ICollection/interfaces/ICollection.h"

class ControladorSistema {
    private:
        ICollection* Pelicula;
        ICollection* Cine;
        ICollection* Usuario;
        ICollection* Reserva;
        static ControladorSistema* instance;
    public:
        static ControladorSistema* getInstance();
        virtual DtPelicula verInfoAdicional() = 0;
        virtual void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion) = 0;
        virtual void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion) = 0;
        virtual void eliminarPelicula(std::string titulo) = 0;
        virtual ICollection* listarPeliculas() = 0;
        virtual void iniciarSesion(std::string nickname, std::string contrasenia) = 0;
        virtual ICollection* listarCines() = 0;
};

#endif /* CONTROLADORSISTEMA_H */

