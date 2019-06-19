#include "ControladorSistema.h"

ControladorSistema::ControladorSistema() {
    colReserva = new OrderedDictionary();
    dicUsuario = new OrderedDictionary();
    dicPelicula = new OrderedDictionary();
    Cines = new OrderedDictionary();
}


void ControladorSistema::altaFuncion(DtFecha fecha, DtHora hora) {
//    std::string titulo;
//    std::cout << "Seleccione una película de la siguiente lista: ";
//    ControladorSistema::listarPeliculas();
//    std::cin >> titulo;
}
void ControladorSistema::altaCine(DtDireccion direccion) {
    int numero;
    std::cout << "Ingrese el numero del cine:";
    std::cin >> numero;
    Cine* nuevocine = new Cine(new DtCine(direccion,numero));
    int agregarmas = 1;
    int capacidadSala;
    int numeroSala;
    while(agregarmas!=0){
        std::cout <<"Ingrese la capacidad:";
        std::cin >>capacidadSala;
        std::cout <<"Ingrese el numero de sala:";
        std::cin>>numeroSala;
        IntKey* keysala = new IntKey {numeroSala};
        Sala* sala = new Sala(capacidadSala,numeroSala);
        nuevocine->getSalas()->add(keysala,sala);
        std::cout <<"Para salir presione 0:";
        std::cin >>agregarmas;
        if(agregarmas == 0){
            break;
        }
    }
    IntKey* keyCine = new IntKey (numero);
    Cines->add(keyCine,nuevocine);
}


void ControladorSistema::altaPelicula(DtPelicula datos) {
    IKey* key = new StringKey(datos.getTitulo());
//    key = datos.getTitulo();
    Pelicula* pelicula = new Pelicula();
    pelicula->setTitulo(datos.getTitulo());
    pelicula->setUrlPoster(datos.getUrlPoster());
    pelicula->setSinopsis(datos.getSinopsis());
    pelicula->setPuntajePromedio(datos.getPuntajePromedio());
    dicPelicula->add(key, pelicula);
}
void ControladorSistema::listarCines(){
    Cine::listarCines(Cines);
}
//void ControladorSistema::eliminarPelicula(std::string titulo) {
//    // Corresponde al caso de uso eliminar pelicula
//    IKey* clave = new String(titulo);
//    ICollectible* (Pelicula *) p;
//    p = (Pelicula *) Pelicula->find(clave);
//    Pelicula->remove(p);
//    delete p;
//    delete clave;
//}

void ControladorSistema::listarPeliculas() {
    Pelicula::listarPeliculas(dicPelicula);
}

//DtPelicula ControladorSistema::seleccionarPelicula(std::string titulo) {
//    IKey clave = new String(titulo);
//    //Corresponde al caso de uso Ver informacion de pelicula
//    DtPelicula *p;
//    p = (DtPelicula *) Pelicula->find(clave);
//
//    return p;
//}

ControladorSistema::~ControladorSistema() {
    
}