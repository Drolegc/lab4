#include "ControladorSistema.h"
#include "../../ICollection/StringKey.h"

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

DtPelicula ControladorSistema::seleccionarPelicula(std::string titulo)
{
    //Corresponde al caso de uso Ver informacion de pelicula
    //IKey clave = new String(titulo);
    StringKey *clave = new StringKey(titulo);
    Pelicula *p = dynamic_cast<Pelicula *>(dicPelicula->find(clave));
    if (p != NULL)
    {
        DtPelicula peli = DtPelicula(p->getTitulo(), p->getUrlPoster(), p->getSinopsis(),p->getPuntajePromedio());
        return peli;
    }else{
        throw std::invalid_argument("Disculpa, no tenemos esa pelicula pr el momento :/");
    }
}

ICollection* ControladorSistema::verInfoAdicional(DtPelicula p){
    //Primero obtener el objeto pelicula
    //clave y coleccionable
    StringKey *clave = new StringKey(p.getTitulo());
    //ICollectible * peli = dicPelicula->find(clave);
    //Crear una coleccion vacia para agregar los cines
    ICollection * CinesConPeli = new List();
    //Obtenemos el iterador del diccionario de Cines
    IIterator *it = dicCine->getIterator();
    
    while(it->hasCurrent()){
        Cine *c = dynamic_cast<Cine*>(it->getCurrent());
        if(c->tienePeli(clave)){
            CinesConPeli->add(it->getCurrent());
        }
    }

    return CinesConPeli;
}


ControladorSistema::~ControladorSistema()
{
}