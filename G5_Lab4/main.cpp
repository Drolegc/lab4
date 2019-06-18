#include <cstdlib>
#include <iostream>

//#include "classes/interfaces/ISistema.h"
#include "classes/interfaces/Fabrica.h"
#include "datatypes/headers/DtDireccion.h"

void MostrarDtPelicula(DtPelicula p);

int main() {
    
    /**************** Solicitud de la instancia para Singleton ****************/
    
    ISistema* controladorSistema = Fabrica::getISistema();
    
    /**************************************************************************/
    
    std::cout << "¡Bienvenido al sistema!" << std::endl;
    std::cout << "Comandos:" << std::endl;
    std::cout << "1) Agregar cine" << std::endl;
    std::cout << "2) ¡Crea tu reserva antes que se agoten los lugares!"<<std::endl;
    std::cout << "0) Salir" << std::endl;
    int command;
    while(command != 0) {
        std::cout << ">";
        std::cin >> command;
        try {
            switch (command) {
               /* case 1:
                    std::string calle;
                    int numero;
                    std::string ciudad;
                    std::cout << "Ingrese la dirección del cine (Calle - Numero - Ciudad): ";
                    std::cin >> calle >> numero >> ciudad;
                    controladorSistema->altaCine(DtDireccion(calle, numero, ciudad));
                break; */
                case 2:
                    std::cout<<"¿Que pelicula quieres ver? ";
                    std::string titulo;
                    std::cin>>titulo;
                    DtPelicula peli = controladorSistema->seleccionarPelicula(titulo);
                    std::cout<<peli.getTitulo();
                break;
            }
        }
        catch (std::invalid_argument) {
            std::cout << "¡Error!" << std::endl;
        }
    }
    return 0;
}
