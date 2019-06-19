#include <cstdlib>
#include <iostream>

//#include "classes/interfaces/ISistema.h"
#include "classes/interfaces/Fabrica.h"
#include "datatypes/headers/DtDireccion.h"
#include "datatypes/headers/DtPelicula.h"

void MostrarDtPelicula(DtPelicula p);
void MostrarCines(ICollection* c);


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
    
//    controladorSistema->listarPeliculas();
    
    std::cout << "¡Bienvenido al sistema!" << std::endl;
    std::cout << "Comandos:" << std::endl;
    std::cout << "1) Agregar cine" << std::endl;
    std::cout << "2) ¡Crea tu reserva antes que se agoten los lugares!"<<std::endl;
    std::cout << "0) Salir" << std::endl;
    int command = -1;
    while(command != 0) {
        std::cout << ">";
        std::cin >> command;
        try {
            switch (command) {
                /*case 1: {
                    std::string calle;
                    int numero;
                    std::string ciudad;
                    std::cout << "Ingrese la dirección del cine (Calle - Numero - Ciudad): ";
                    std::cin >> calle >> numero >> ciudad;
                    controladorSistema->altaCine(DtDireccion(calle, numero, ciudad));
                break;*/
                case 2:
                    std::cout<<"¿Que pelicula quieres ver? ";
                    std::string titulo;
                    int YN;
                    std::cin>>titulo;
                    DtPelicula peli = controladorSistema->seleccionarPelicula(titulo);
                    std::cout<<peli.getTitulo()<<std::endl;
                    std::cout<<"¿Quieres ver en que cines esta esta pelicula?"<<std::endl;
                    std::cin>>YN;
                    if(YN == 'Y'){
                        ICollection *cines = controladorSistema->verInfoAdicional(peli);
                        MostrarCines(cines);
                    }else{
                        break;
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

void MostrarCines(ICollection* c){
    IIterator * it = c->getIterator();
    while(it->hasCurrent())
    {
        Cine * cine = dynamic_cast<Cine *>(it->getCurrent());
        std::cout<<cine->getNumero()<<std::endl;;
    }
    
}