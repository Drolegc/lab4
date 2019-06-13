#ifndef ISISTEMA_H
#define ISISTEMA_H

class ISistema {
    public:
        virtual DtPelicula verInfoAdicional() = 0;
        virtual void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion) = 0;
        virtual void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion) = 0;
        virtual void eliminarPelicula(std::string titulo) = 0;
        virtual DtPelicula listarPeliculas() = 0;
        virtual void iniciarSesion(std::string nickname, std::string contrasenia) = 0;
        virtual DtCine listarCines() = 0;
};

#endif /* ISISTEMA_H */

