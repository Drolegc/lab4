#ifndef CONTROLADORSISTEMA_H
#define CONTROLADORSISTEMA_H

#include <iostream>
/* -- L.h de las key tipo int e string -- */
#include "../../ICollection/StringKey.h"
/* -- INTERFACES -- */
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
/* -- COLLECTIONS -- */
#include "../../ICollection/collections/OrderedDictionary.h"
/* -- DataTypes -- */
#include "../../datatypes/headers/DtDireccion.h"
#include "../../datatypes/headers/DtPelicula.h"
/* -- CLASES -- */
#include "../headers/Pelicula.h"
#include "../headers/Cine.h"
#include "../headers/Credito.h"
#include "../headers/Debito.h"
#include "../headers/Usuario.h"
#include "../interfaces/ISistema.h"

class ControladorSistema : public ISistema {
    private:
        IDictionary* dicPelicula;
        IDictionary* dicCine;
        IDictionary* dicUsuario;
        ICollection* colReserva;
    public:
        ControladorSistema();
        
        /******************************** CINES ********************************/
        
        void altaCine(DtDireccion direccion);
//        ICollection* listarCines();
        
        /****************************** FUNCIONES ******************************/
        
//        void altaFuncion(DtFecha fecha, DtHora hora);
        
        /****************************** PELICULAS ******************************/
        
//        void eliminarPelicula(std::string titulo);
//        ICollection* listarPeliculas();
        DtPelicula seleccionarPelicula(std::string titulo);
//        DtPelicula verInfoAdicional();
        
        /****************************** RESERVAS ******************************/
        
//        void reservaCredito(int asientos, std::string financiera, int porcentajeDescuento, int funcion);
//        void reservaDebito(int asientos, int costoTotal, std::string bancoEmisor, int funcion);
        
        /****************************** USUARIOS ******************************/
        
//        void iniciarSesion(std::string nickname, std::string contrasenia);
        
        /**********************************************************************/
        
        ~ControladorSistema();
};

#endif /* CONTROLADORSISTEMA_H */