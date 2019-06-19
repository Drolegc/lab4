#include "ControladorSistema.h"

ControladorSistema::ControladorSistema() {
    dicPelicula = new OrderedDictionary();
    dicCine = new OrderedDictionary();
    dicUsuario = new OrderedDictionary();
    colReserva = new OrderedDictionary();
    
}

void ControladorSistema::altaFuncion(DtFecha fecha, DtHora hora) {
//    std::string titulo;
//    std::cout << "Seleccione una película de la siguiente lista: ";
//    ControladorSistema::listarPeliculas();
//    std::cin >> titulo;
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
//    //Corresponde al caso de uso Ver informacion de pelicula
//    IKey clave = new String(titulo);
//    DtPelicula *p;
//    p = (DtPelicula *) Pelicula->find(clave);
//
//    return p;
//}

ControladorSistema::~ControladorSistema() {
    
}