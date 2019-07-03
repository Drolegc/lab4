#ifndef CONTROLADORSISTEMA_H
#define CONTROLADORSISTEMA_H
#include "../../ICollection/StringKey.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/IntKey.h"
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtCine.h"
#include "../../datatypes/headers/DtPelicula.h"
#include "../headers/Pelicula.h"
#include "../headers/Cine.h"
#include "../headers/Sala.h"
#include "../headers/Credito.h"
#include "../headers/Debito.h"
#include "../headers/Funcion.h"
#include "../headers/Usuario.h"
#include "../interfaces/ISistema.h"
//class Funcion;

class ControladorSistema : public ISistema {
    private:
        ICollection* colReserva;
        IDictionary* dicPelicula;
        IDictionary* dicUsuario;
        IDictionary* dicCines;
        Usuario *sesion;
    public:

        ControladorSistema();

        /******************************** CINES ********************************/
        void infoPeliculas();
        void altaCine(DtDireccion direccion);
        void listarCines();
        /****************************** FUNCIONES ******************************/

        void altaFuncion(std::string titulo, int numeroCine, int numeroSala, DtFecha fecha, DtHora hora);
//        void listarFunciones();

        /****************************** PELICULAS ******************************/

        void login(std::string nickname, std::string password);
        void altaPelicula(DtPelicula datos);
        void comentarPelicula();
        void eliminarPelicula();
        DtPelicula seleccionarPelicula(std::string titulo);
        void listarPeliculas();
//        DtPelicula seleccionarPelicula(std::string titulo);
//        DtPelicula verInfoAdicional();
        ICollection* verInfoAdicional(DtPelicula p);
        ICollection* SeleccionarCine(int numCine,std::string titulo);
        void puntuarPelicula();

        /****************************** RESERVAS ******************************/

//        void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion);
//        void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion);
        void pagoDebito(int asientos,std::string banco,int funcion,int cine);
        void pagoCredito(int asientos,std::string financiera,int funcion);

        /****************************** USUARIOS ******************************/

        void iniciarSesion(string nickname, string password);
        void cerrarSesion();
        Usuario* getUsuarioLogeado();
        bool getAdminStatus();
        void MostrarReservas();
        void altaUsuario(std::string nickname, std::string urlimagen, std::string password);
        /**********************************************************************/
        void verComentariosypuntajedepelicula(string _titulo);
        ~ControladorSistema();
};

#endif /* CONTROLADORSISTEMA_H */
