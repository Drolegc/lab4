#include <cstdlib>
#include <iostream>

//#include "classes/interfaces/ISistema.h"
#include "classes/interfaces/Fabrica.h"
#include "datatypes/headers/DtDireccion.h"

int main() {

    /**************** Solicitud de la instancia para Singleton ****************/

    ISistema* controladorSistema = Fabrica::getISistema();

    /**************************************************************************/

    std::cout << "¡Bienvenido al sistema!" << std::endl;
    std::cout << "Comandos:" << std::endl;
    std::cout << "1) Agregar cine" << std::endl;
    std::cout << "0) Salir" << std::endl;
    int command;
    while(command != 0) {
        std::cout << ">";
        std::cin >> command;
        try {
            if (command==1) {
                    std::string calle;
                    std::string ciudad;
                    int numero;
                    std::cout << "Ingrese la dirección del cine (Calle - Numero - Ciudad): ";
                    std::cin >> calle >> numero >> ciudad;
                    controladorSistema->altaCine(DtDireccion(calle, numero, ciudad));
                }
                else if(command == 2){
                    controladorSistema->listarCines();
                }
            }
        catch (const std::invalid_argument ia) {
            std::cout << ia.what() << std::endl;
        }
    }
    return 0;
}

