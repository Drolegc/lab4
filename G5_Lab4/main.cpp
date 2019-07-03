#include <cstdlib>
#include <iostream>
#include <stdexcept>


//#include "classes/interfaces/ISistema.h"
#include "classes/interfaces/Fabrica.h"
#include "datatypes/headers/DtDireccion.h"
#include "datatypes/headers/DtPelicula.h"
#include "auxiliar.cpp"

void MostrarDtPelicula(DtPelicula p);

int main()
{
dance();
    /**************** Solicitud de la instancia para Singleton ****************/

    ISistema *controladorSistema = Fabrica::getISistema();

    /**************************************************************************/

    std::string titulo;
    std::string urlPoster;
    std::string sinopsis;
    int puntajePromedio;

    std::cout << "Cargando datos de prueba..." << std::endl;

    titulo = "Avatar";
    urlPoster = "www.avatar.com";
    sinopsis = "Sinopsis de Avatar";
    puntajePromedio = 0;

    controladorSistema->altaPelicula(DtPelicula(titulo, urlPoster, sinopsis, puntajePromedio));

    titulo = "Buscando_a_Nemo";
    urlPoster = "www.buscandoanemo.com";
    sinopsis = "Sinopsis de Buscando a Nemo";
    puntajePromedio = 0;

    controladorSistema->altaPelicula(DtPelicula(titulo, urlPoster, sinopsis, puntajePromedio));

    titulo = "Rapido_y_Furioso";
    urlPoster = "www.fastandfurious.com";
    sinopsis = "Sinopsis de Rapido y Furioso";
    puntajePromedio = 0;

    controladorSistema->altaPelicula(DtPelicula(titulo, urlPoster, sinopsis, puntajePromedio));
    controladorSistema->altaUsuario("usuario1", "url", "password");
    controladorSistema->altaUsuario("usuario2", "url", "password2");

   // current date/time based on current system
   /* */
   std::cout<<"Fecha sistema: "<<std::endl;
   DtFecha* fecha = controladorSistema->getSystemDate();
   DtHora* hora = controladorSistema->getSystemHour();
   std::cout<<"Dia: "<<fecha->getDia()<<std::endl;
   std::cout<<"Mes: "<<fecha->getMes()<<std::endl;
   std::cout<<"Anio: "<<fecha->getAnio()<<std::endl;

   std::cout<<"Hora sistema: "<<std::endl;
   std::cout<<"Hora: "<<hora->getHora()<<std::endl;
   std::cout<<"Minutos: "<<hora->getMinutos()<<std::endl;



    int command = -1;
    while (command != 0)
    {

        logo();
        lista_comandos();
        muestroCursor(9);
        std::cin >> command;
        try
        {
            switch (command)
            {
            case 1:
            {
                std::string nickname;
                std::string contrasenia;
                logo();
                std::cout << "\n\n          \033[1;31m>>>>>>>>>>\033[0m             INICIO DE SESIÒN           \033[1;31m<<<<<<<<<<\033[0m                   " << std::endl;
                std::cout << "\n\n                        USUARIO: ";
                std::cin >> nickname;
                std::cout << "                       PASSWORD: ";
                std::cin >> contrasenia;
                controladorSistema->iniciarSesion(nickname, contrasenia);
            }
            break;
            case 2:
            { //ALTA CINE
                if (controladorSistema->getUsuarioLogeado() != NULL)
                {
                    if (controladorSistema->getAdminStatus() == true)
                    {
                        std::string calle;
                        std::string ciudad;
                        int numero;
                        logo();
                        std::cout << "\n        \033[1;31m>>>>>>>>>>\033[0m    ALTA CINE - INGRESE DATOS DEL CINE     \033[1;31m<<<<<<<<<<\033[0m                   \n\n"
                                  << std::endl;
                        std::cout << "                  DIRECCIÓN:          " << std::endl;
                        std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;

                        std::cout << "                        CALLE: ";
                        std::cin >> calle;
                        std::cout << "                       NUMERO: ";
                        std::cin >> numero;
                        std::cout << "                       CIUDAD: ";
                        std::cin >> ciudad;
                        controladorSistema->altaCine(DtDireccion(calle, numero, ciudad));
                    }
                    else
                    {
                        throw std::invalid_argument("Debe iniciar sesión como administrador para realizar ésta acción");
                    }
                }
                else
                {
                    throw std::invalid_argument("Debe iniciar sesión para realizar ésta acción");
                }
            }
            break;
            case 3:
            {
                //ALTA FUNCION
                if(controladorSistema->getUsuarioLogeado() != NULL) {
                    if(controladorSistema->getAdminStatus() == true) {
                        int dia;
                        int mes;
                        int anio;
                        int hora;
                        int minutos;
                        int numeroCine;
                        int numeroSala;
                        std::string titulo;
                         logo();
                        std::cout << std::endl;
                        controladorSistema->listarPeliculas();
                        std::cout << std::endl;
                        std::cout << "              Seleccione la película deseada (titulo): ";
                        std::cin >> titulo;
                        std::cout << std::endl;
                        std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;
                        std::cout << "                 CINES" << std::endl;
                        std::cout << std::endl;
                        controladorSistema->listarCines();
                        std::cout << std::endl;
                        std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;
                        std::cout << std::endl;
                        std::cout << "              Ingrese numero de cine: ";
                        std::cin >> numeroCine;
                        std::cout << "              Seleccione la sala deseada (numeroSala): ";
                        std::cin >> numeroSala;
                        std::cout << "              Ingrese la fecha de la función (Dia - Mes - Año): ";
                        std::cin >> dia >> mes >> anio;
                        std::cout << "              Ingrese la hora de la función (Hora - Minutos): ";
                        std::cin >> hora >> minutos;
                        controladorSistema->altaFuncion(titulo, numeroCine, numeroSala, DtFecha(dia, mes, anio), DtHora(hora, minutos));
                        std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;

                        std::cout << "\n                                    Presione enter  para continuar..." << std::endl;
                        std::getchar();
                        std::getchar();
                    }
                    else {
                        throw std::invalid_argument("Debe iniciar sesión como administrador para realizar ésta acción");
                    }
                }
                else {
                    throw std::invalid_argument("Debe iniciar sesión para realizar ésta acción");
                }
            }
            break;
            case 4:
            { //crear reserva
                if (controladorSistema->getUsuarioLogeado() != NULL)
                {
                    char YN;
                    std::string titulo;
                    int id_funcion;
                    int id_cine;

                    do
                    {
                        controladorSistema->listarPeliculas();
                        std::cout << "                   ¿Que pelicula quieres ver? ";

                        std::cin >> titulo;
                        DtPelicula peli = controladorSistema->seleccionarPelicula(titulo);
                        std::cout<<"                   Url Poster: "<<peli.getUrlPoster()<<std::endl;
                        std::cout<<"                   Sinopsis: "<<peli.getSinopsis()<<std::endl;

                        std::cout << "                   ¿Quieres ver en que cines esta la pelicula?(Y/N)";
                        std::cin >> YN;
                        if (YN == 'Y' or YN == 'y')
                        {
                            //OJO CON ESA VARIABLE CINESfUNCIONES

                            ICollection *cinesFunciones = controladorSistema->verInfoAdicional(peli);
                            Cine::CinesConPeli(cinesFunciones);

                            std::cout << "                   ¿En que cine te gustaria? Ingresa su numero: ";
                            std::cin >> id_cine;
                            cinesFunciones = controladorSistema->SeleccionarCine(id_cine, peli.getTitulo());
                            Funcion::FuncionesConPeli(cinesFunciones);

                            std::cout << "                   ¿En que funcion te gustaria? Ingresa su numero: ";

                            std::cin >> id_funcion; //Funciona como id_funcion
                        }
                        std::cout << "                   ¿Crear reserva (Y) o buscar otra pelicula (N)?"<<std::endl;
                        std::cout << "                   Cancelar (C)"<<std::endl;
                        std::cin >> YN;
                        if((YN == 'C') or (YN == 'c')){
                            std::__throw_invalid_argument("Reserva cancelada");
                        }else if(YN == 'Y' or YN == 'y'){
                            break;
                        }

                    } while (true);

                    std::cout << "                   ¿Pago debito (D) o credito (C)?";
                    std::cin >> YN;
                    if (YN == 'D' or YN == 'd')
                    {
                        //Asientos,Banco id_funcion
                        int asientos;
                        std::string banco;
                        std::cout << "                   ¿Cantidad de asientos?";
                        std::cin >> asientos;
                        std::cout << "                   Banco de la tarjeta: ";
                        std::cin >> banco;
                        std::cout << "                   Procesando total ..." << std::endl;
                        int total = asientos * 250;
                        std::cout << "                   El total es: $" << total << std::endl;
                        std::cout << "                   ¿confirmar? Y/N: ";
                        char YN;
                        std::cin >> YN;
                        if (YN == 'Y' or YN == 'y')
                        {
                            controladorSistema->pagoDebito(asientos, banco, id_funcion, id_cine, total);
                            std::cout << "                   Reserva mediante debito lista! Que disfrutes la pelicula! " << std::endl;
                            std::getchar();
                            std::getchar();
                            //Falta agregar UserLogeado y setReserva de user
                        }
                        else
                        {
                            std::__throw_invalid_argument("Reserva cancelada");
                        }
                    }
                    else if (YN == 'C' or YN == 'c')
                    {
                        int asientos;
                        std::string financiera;
                        std::cout << "                   ¿Cantidad de asientos?";
                        std::cin >> asientos;
                        std::cout << "                   Financiera de la tarjeta: " << std::endl;
                        std::cin >> financiera;
                        std::cout << "                   Procesando total..." << std::endl;
                        //recordar que id_cine funciona como id_funcion (cambiar nombre de variable)
                        int total = (asientos * 250) * 0.75; //Asumimos %25 porciento de descuento por financiera
                        std::cout << "                   El total es: $" << total << std::endl;
                        std::cout << "                   ¿confirmar? Y/N: ";
                        char YN;
                        std::cin >> YN;
                        if (YN == 'Y' or YN == 'y')
                        {
                            controladorSistema->pagoCredito(asientos, financiera,id_funcion, id_cine, total);
                            std::cout << "                   Reserva mediante credito lista! Que disfrutes la pelicula! " << std::endl;
                            std::getchar();
                            std::getchar();
                        }
                    }
                    else
                    {
                        throw std::invalid_argument("que tipo de error");
                    }
                }

                else
                {
                    throw std::invalid_argument("Debe iniciar sesión para realizar ésta acción");
                }
            }
            break;
        case 5:
        { //Puntuar pelicula
            if (controladorSistema->getUsuarioLogeado() != NULL)
            {
                logo();
                controladorSistema->puntuarPelicula();
            }
            else
            {
                throw std::invalid_argument("Debe iniciar sesión para realizar ésta acción");
            }
        }
        break;
        case 6:
        {
            if (controladorSistema->getUsuarioLogeado() != NULL)
            {
                logo();
                controladorSistema->comentarPelicula();
            }
            else
            {
                throw std::invalid_argument("Debe iniciar sesión para realizar ésta acción");
            }
        }
        break;
        case 7:
        {
            if (controladorSistema->getUsuarioLogeado() != NULL)
            {
                if (controladorSistema->getAdminStatus() == true)
                {
                    logo();

                    controladorSistema->eliminarPelicula();
                }
                else
                {
                    throw std::invalid_argument("Debe iniciar sesión como administrador para realizar ésta acción");
                }
            }
            else
            {
                throw std::invalid_argument("Debe iniciar sesión para realizar ésta acción");
            }
        }
        break;
        case 8:
        {
            logo();

            controladorSistema->infoPeliculas();
        }
        break;
        case 9: {
                logo();
                std::string nombrePelicula;
                controladorSistema->listarPeliculas();
                std::cout << "               Ingrese nombre de la pelicula:";
                std::cin >> nombrePelicula;
                logo();
                controladorSistema->verComentariosypuntajedepelicula(nombrePelicula);
            }
        break;
        case 10:
        {/*funcion para el proceso de testeo, pone sesion a null para poder cambiar de usuario
                y realizar comentarios y puntajes*/
                controladorSistema->cerrarSesion();
            }
        break;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "\n                      \033[1;31m Error:\033[0m "<< e.what() << std::endl;
        system(" aplay error.wav  > /dev/null 2>&1  ");
        std::getchar();
        std::getchar();

    }
}
return 0;
}
