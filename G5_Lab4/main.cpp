#include <cstdlib>
#include <iostream>

//#include "classes/interfaces/ISistema.h"
#include "classes/interfaces/Fabrica.h"
#include "datatypes/headers/DtDireccion.h"
#include "datatypes/headers/DtPelicula.h"

int main() {

    /**************** Solicitud de la instancia para Singleton ****************/

    ISistema* controladorSistema = Fabrica::getISistema();

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

    controladorSistema->altaPelicula(DtPelicula (titulo, urlPoster, sinopsis, puntajePromedio));

    titulo = "Buscando a Nemo";
    urlPoster = "www.buscandoanemo.com";
    sinopsis = "Sinopsis de Buscando a Nemo";
    puntajePromedio = 0;

    controladorSistema->altaPelicula(DtPelicula (titulo, urlPoster, sinopsis, puntajePromedio));

    titulo = "Rapido y Furioso";
    urlPoster = "www.fastandfurious.com";
    sinopsis= "Sinopsis de Rapido y Furioso";
    puntajePromedio = 0;

    controladorSistema->altaPelicula(DtPelicula (titulo, urlPoster, sinopsis, puntajePromedio));

    controladorSistema->listarPeliculas();

    std::cout << "¡Bienvenido al sistema!" << std::endl;
    std::cout << "Comandos:" << std::endl;
    std::cout << "1) Agregar cine" << std::endl;
    std::cout << "2) Agregar función" << std::endl;
    std::cout << "3) Listar cines" << std::endl;
    std::cout << "0) Salir" << std::endl;
    int command = -1;
    while(command != 0) {
        std::cout << ">";
        std::cin >> command;
        try {
            switch (command) {
                case 1: {
                    std::string calle;
                    std::string ciudad;
                    int numero;
                    std::cout << "Ingrese la direcciรณn del cine (Calle - Numero - Ciudad): ";
                    std::cin >> calle >> numero >> ciudad;
                    controladorSistema->altaCine(DtDireccion(calle, numero, ciudad));
                }
                break;
                case 2: {
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
                case 3: {
                    controladorSistema->listarCines();
                }
                break;
                case 4: {
                    controladorSistema->comentarPelicula();
                }
                break;
            }
        }
        catch (std::invalid_argument) {
            std::cout << "¡Error!" << std::endl;
        }
    }
    return 0;
}

