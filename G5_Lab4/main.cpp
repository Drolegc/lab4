#include <cstdlib>
#include <iostream>

//#include "classes/interfaces/ISistema.h"
#include "classes/interfaces/Fabrica.h"
#include "datatypes/headers/DtDireccion.h"
#include "datatypes/headers/DtPelicula.h"

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

    controladorSistema->listarPeliculas();
    /* --- CREAR RESERVA --- */

    std::string calle = "Spinola";
    std::string ciudad = "Maldonado";
    int numero = 99;

    controladorSistema->altaCine(DtDireccion(calle, numero, ciudad));

    /* --- /CREAR RESERVA --- */
    std::cout << "¡Bienvenido al sistema!" << std::endl;
    std::cout << "Comandos:" << std::endl;
    std::cout << "1) Agregar cine" << std::endl;
    std::cout << "2) ¡Crea tu reserva antes que se agoten los lugares!" << std::endl;
    std::cout << "3) Agregar función" << std::endl;
    std::cout << "4) Listar cines" << std::endl;
    std::cout << "0) Salir" << std::endl;
    int command = -1;
    while (command != 0)
    {
        std::cout << ">";
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
                std::cout << "Ingrese la direcciรณn del cine (Calle - Numero - Ciudad): ";
                std::cin >> calle >> numero >> ciudad;
                controladorSistema->altaCine(DtDireccion(calle, numero, ciudad));
            }
            break;
            case 2:
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
                    ICollection *cinesFunciones = controladorSistema->verInfoAdicional(peli);
                    MostrarCines(cinesFunciones);
                    int id_cine;
                    std::cout << "¿En que cine te gustaria? Ingresa su id: " << std::endl;
                    std::cin >> id_cine;
                    cinesFunciones = controladorSistema->SeleccionarCine(id_cine, peli.getTitulo());
                    MostrarFunciones(cinesFunciones);
                    std::cout<<"¿En que funcion te gustaria? Ingresa su id "<<std::endl;
                    std::cin>>id_cine; //Funciona como id_funcion
                    std::cout<<"¿Pago debito (D) o credito (C)?"<<std::endl;
                    if(YN = 'D'){
                        //Asientos,Banco id_funcion
                        int Asientos;
                        std::string banco;
                        std::cout<<"¿Cantidad de asientos?";
                        std::cin>>Asientos;
                        std::cout<<"Banco de la tarjeta: "<<std::endl;
                        std::cin>>banco;
                        std::cout<<"Procesando total ..."<<std::endl;
                        controladorSistema->pagoDebito(Asientos,banco,id_cine);
                        //Falta agregar UserLogeado y setReserva de user

                    }else if(YN == 'C'){

                    }else{

                    }
                    
                }
                else
                {
                    break;
                }
            }
            break;
            case 3:
            {
                int dia;
                int mes;
                int anio;
                int hora;
                int minutos;
                std::cout << "Ingrese la fecha de la función (Dia - Mes - Año): ";
                std::cin >> dia >> mes >> anio;
                std::cout << "Ingrese la hora de la función (Hora - Minutos): ";
                std::cin >> hora >> minutos;
                controladorSistema->altaFuncion(DtFecha(dia, mes, anio), DtHora(hora, minutos));
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
            }
        }
        catch (std::invalid_argument)
        {
            std::cout << "¡Error!" << std::endl;
        }
    }
    return 0;
}

void MostrarCines(ICollection *c)
{
    IIterator *it = c->getIterator();
    if (!it->hasCurrent())
    {
        std::cout << "sorry" << std::endl;
    }
    while (it->hasCurrent())
    {
        Cine *cine = dynamic_cast<Cine *>(it->getCurrent());
        std::cout << cine->getNumero() << std::endl;
        it->next();
    }
}

void MostrarFunciones(ICollection *c)
{
    IIterator *it = c->getIterator();
    if (!it->hasCurrent())
    {
        std::cout << "sorrySinFunciones" << std::endl;
    }
    while (it->hasCurrent())
    {
        DtFuncion *f = dynamic_cast<DtFuncion *>(it->getCurrent());
        std::cout << "Numero de funcion: " <<f->getNumero()<< std::endl;
        it->next();
    }

}