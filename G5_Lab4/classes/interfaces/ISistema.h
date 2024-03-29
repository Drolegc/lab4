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
        virtual DtHora* getSystemHour() = 0;
        virtual DtFecha* getSystemDate() = 0;
        virtual void altaFuncion(std::string titulo, int numeroCine, int numeroSala, DtFecha fecha, DtHora hora) = 0;
//        virtual void listarFunciones() = 0;
        virtual void altaPelicula(DtPelicula datos) = 0;
        virtual void altaCine(DtDireccion direccion) = 0;
        virtual void comentarPelicula() = 0;
        virtual void infoPeliculas() = 0;
        virtual void eliminarPelicula() = 0;
       virtual void iniciarSesion(std::string nickname, std::string contrasenia)=0;
       virtual void cerrarSesion()=0;
       virtual Usuario* getUsuarioLogeado() = 0;
       virtual bool getAdminStatus() = 0;
        virtual void listarPeliculas() = 0;
        virtual void puntuarPelicula() = 0;
        virtual  void altaUsuario(std::string nickname, std::string urlimagen, std::string password) = 0;
//        virtual void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion);
//        virtual void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion);
       virtual DtPelicula seleccionarPelicula(std::string titulo) = 0;
       virtual ICollection* verInfoAdicional(DtPelicula p) = 0;
//        virtual DtPelicula verInfoAdicional();
        virtual void listarCines() = 0;
        virtual ICollection* SeleccionarCine(int numCine,std::string titulo) = 0;
        virtual void pagoDebito(int asientos,std::string banco,int funcion,int cine,int total) = 0;
        virtual void pagoCredito(int asientos,std::string financiera,int funcion, int cine,int total) = 0;
        virtual void MostrarReservas()=0;
        virtual ~ISistema();
        virtual void verComentariosypuntajedepelicula(std::string _titulo)=0;
};

#endif /* ISISTEMA_H */

