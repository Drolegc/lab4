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
#include "../headers/Usuario.h"
#include "../interfaces/ISistema.h"

class ControladorSistema : public ISistema {
    private:
        IDictionary* dicPelicula;
        IDictionary* colReserva;
        IDictionary* dicUsuario;
        IDictionary* dicCines;
    public:
        ControladorSistema();
        void comentarPelicula();
        /******************************** CINES ********************************/

        void altaCine(DtDireccion direccion);

        /****************************** FUNCIONES ******************************/

        void altaFuncion(DtFecha fecha, DtHora hora);

        /****************************** PELICULAS ******************************/

        void altaPelicula(DtPelicula datos);
//        void eliminarPelicula(std::string titulo);
//        ICollection* listarPeliculas();
        DtPelicula seleccionarPelicula(std::string titulo);
        void listarPeliculas();
//        DtPelicula seleccionarPelicula(std::string titulo);
//        DtPelicula verInfoAdicional();
        ICollection* verInfoAdicional(DtPelicula p);
        ICollection* SeleccionarCine(int numCine,std::string titulo);
        
        /****************************** RESERVAS ******************************/

//        void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion);
//        void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion);
        void pagoDebito(int asientos,std::string banco,int funcion);
        void pagoCredito(int asientos,std::string financiera,int funcion);

        /****************************** USUARIOS ******************************/

//        void iniciarSesion(std::string nickname, std::string contrasenia);

        /**********************************************************************/

        void listarCines();
        ~ControladorSistema();
};

#endif /* CONTROLADORSISTEMA_H */