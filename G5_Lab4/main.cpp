#include <cstdlib>
#include <iostream>

//#include "classes/interfaces/ISistema.h"
#include "classes/interfaces/Fabrica.h"
#include "datatypes/headers/DtDireccion.h"
#include "datatypes/headers/DtPelicula.h"
#include "classes/sources/auxiliar.cpp"

void MostrarDtPelicula(DtPelicula p);
void MostrarCines(ICollection *c);
void MostrarFunciones(ICollection *c);

int main()
{

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

    titulo = "Buscando a Nemo";
    urlPoster = "www.buscandoanemo.com";
    sinopsis = "Sinopsis de Buscando a Nemo";
    puntajePromedio = 0;

    controladorSistema->altaPelicula(DtPelicula(titulo, urlPoster, sinopsis, puntajePromedio));

    titulo = "Rapido y Furioso";
    urlPoster = "www.fastandfurious.com";
    sinopsis = "Sinopsis de Rapido y Furioso";
    puntajePromedio = 0;

    controladorSistema->altaPelicula(DtPelicula(titulo, urlPoster, sinopsis, puntajePromedio));

    int command = -1;
    while (command != 0)
    {
        logo();
        lista_comandos();
        muestroCursor(4);
        std::cin >> command;
        try
        {
            switch (command)
            {
            case 1:
            {
                std::string calle;
                std::string ciudad;
                int numero;
                logo();
                std::cout << "        \033[1;31m>>>>>>>>>>\033[0m    ALTA CINE - INGRESE DATOS DEL CINE     \033[1;31m<<<<<<<<<<\033[0m                   " << std::endl;
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
            break;
            case 2:
            {

                int dia;
                int mes;
                int anio;
                int hora;
                int minutos;
                int numeroCine;
                int numeroSala;
                std::string titulo;

                std::cout << std::endl;
                controladorSistema->listarPeliculas();
                std::cout << std::endl;
                std::cout << "Seleccione la película deseada (titulo): ";
                std::cin >> titulo;
                std::cout << std::endl;
                controladorSistema->listarCines();
                std::cout << std::endl;
                std::cout << "Seleccione el cine deseado (numeroCine): ";
                std::cin >> numeroCine;
                std::cout << "Seleccione la sala deseada (numeroSala): ";
                std::cin >> numeroSala;
                std::cout << "Ingrese la fecha de la función (Dia - Mes - Año): ";
                std::cin >> dia >> mes >> anio;
                std::cout << "Ingrese la hora de la función (Hora - Minutos): ";
                std::cin >> hora >> minutos;
                controladorSistema->altaFuncion(titulo, numeroCine, numeroSala, DtFecha(dia, mes, anio), DtHora(hora, minutos));
            }
            break;
            case 3:
            {
                std::cout << "¿Que pelicula quieres ver? ";
                std::string titulo;
                char YN;
                std::cin >> titulo;
                DtPelicula peli = controladorSistema->seleccionarPelicula(titulo);
                std::cout << peli.getTitulo() << std::endl;
                std::cout << "¿Quieres ver en que cines esta la pelicula?" << std::endl;
                std::cin >> YN;
                if (YN == 'Y')
                {
                    //OJO CON ESA VARIABLE CINESfUNCIONES

                    ICollection *cinesFunciones = controladorSistema->verInfoAdicional(peli);
                    MostrarCines(cinesFunciones);

                    int id_cine;
                    std::cout << "¿En que cine te gustaria? Ingresa su id: " << std::endl;
                    std::cin >> id_cine;
                    cinesFunciones = controladorSistema->SeleccionarCine(id_cine, peli.getTitulo());
                    MostrarFunciones(cinesFunciones);

                    std::cout << "¿En que funcion te gustaria? Ingresa su id " << std::endl;
                    int id_funcion;
                    std::cin >> id_funcion; //Funciona como id_funcion

                    std::cout << "¿Pago debito (D) o credito (C)?" << std::endl;
                    std::cin >> YN;
                    if (YN == 'D')
                    {
                        //Asientos,Banco id_funcion
                        int Asientos;
                        std::string banco;
                        std::cout << "¿Cantidad de asientos?";
                        std::cin >> Asientos;
                        std::cout << "Banco de la tarjeta: " << std::endl;
                        std::cin >> banco;
                        std::cout << "Procesando total ..." << std::endl;
                        controladorSistema->pagoDebito(Asientos, banco, id_cine, id_funcion);
                        //Falta agregar UserLogeado y setReserva de user
                    }
                    else if (YN == 'C')
                    {
                        int Asientos;
                        std::string financiera;
                        std::cout << "¿Cantidad de asientos?";
                        std::cin >> Asientos;
                        std::cout << "Financiera de la tarjeta: " << std::endl;
                        std::cin >> financiera;
                        std::cout << "Procesando total..." << std::endl;
                        //recordar que id_cine funciona como id_funcion (cambiar nombre de variable)
                        controladorSistema->pagoCredito(Asientos, financiera, id_cine);
                    }
                    else
                    {
                        throw std::invalid_argument("");
                    }
                }
            }
            break;
            case 4:
            {
                controladorSistema->listarCines();
            }
            break;
            case 5:
            {
                controladorSistema->comentarPelicula();
            }
            break;
            case 6:
            {
                controladorSistema->infoPeliculas();
            }
            break;
            }
        }
        catch (std::invalid_argument)
        {
            std::cout << "\033[1;31m¡Error!\033[0m" << std::endl;
        }
    }
    return 0;
}

void MostrarCines(ICollection *c)
{
    IIterator *it = c->getIterator();
    if (!it->hasCurrent())
    {
        std::cout << "No tenemos cines :/" << std::endl;
        throw std::invalid_argument("");
    }
    while (it->hasCurrent())
    {
        Cine *cine = dynamic_cast<Cine *>(it->getCurrent());
        std::cout << "Id del cine: " << cine->getNumero() << std::endl;
        it->next();
    }
}

void MostrarFunciones(ICollection *c)
{
    IIterator *it = c->getIterator();
    if (!it->hasCurrent())
    {
        std::cout << "Sin funciones para esa pelicula, vuelve pronto" << std::endl;
        throw std::invalid_argument("");
    }
    while (it->hasCurrent())
    {
        DtFuncion *f = dynamic_cast<DtFuncion *>(it->getCurrent());
        std::cout << "Numero de funcion: " << f->getNumero() << std::endl;
        it->next();
    }
}