#ifndef CONTROLADORSISTEMA_H
#define COTROLADORSISTEMA_H

#include "../headers/Pelicula.h"
#include "../headers/Cine.h"
#include "../headers/Credito.h"
#include "../headers/Debito.h"
#include "../headers/Usuario.h"
#include "../interfaces/ISistema.h"

class ControladorSistema : ISistema {
    private:
        IDictionary* Pelicula;
        IDictionary* Cine;
        IDictionary* Usuario;
        ICollection* Reserva;
    public:
        ControladorSistema();
        void altaFuncion(DtFecha fecha, DtHora hora);
        DtPelicula verInfoAdicional() = 0;
        void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion) = 0;
        void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion) = 0;
        void eliminarPelicula(std::string titulo) = 0;
        ICollection* listarPeliculas() = 0;
        void iniciarSesion(std::string nickname, std::string contrasenia) = 0;
        ICollection* listarCines() = 0;
        ~ControladorSistema();
};

#endif /* CONTROLADORSSISTEMA_H */