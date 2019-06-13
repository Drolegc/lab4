#include "../headers/Pelicula.h"
using namespace str;

Pelicula::Pelicula(std::string titulo, std::string urlPoster, std::string sinopsis) {
    this->titulo = titulo;
    this->urlPoster = urlPoster;
    this->sinopsis = sinopsis;
    this->puntajePromedio = 0;
}

std::string Pelicula::getTitulo() {
    return this->titulo;
}

std::string Pelicula::getUrlPoster() {
    return this->urlPoster;
}

std::string Pelicula::getSinopsis() {
    return this->urlPoster;
}

void Pelicula::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

void Pelicula::setUrlPoster(std::string urlPoster) {
    this->urlPoster = urlPoster;
}

void Pelicula::setSinopsis(std::string sinopsis) {
    this->sinopsis = sinopsis;
}

void Pelicula::setPuntajePromedio(int puntajePromedio) {
    this->puntajePromedio = puntajePromedio;
}

Pelicula::~Pelicula() {
    
}
ICollection Pelicula::listarPeliculas(){
    ICollection* lisPeliculas = new List(Pelicula);
    IIterator *it = Pelicula->getIterator();    
    while(it->hasCurrent()){
       lisPeliculas->add(it->current());   
       it->hasCurrent()->getTitulo();
       it->next();
    }
    delete it;
    return lisPeliculas;
}
string Pelicula::getTitulo(){
    return this->titulo;
}
string Pelicula::getUrlPoster(){
    return this->urlPoster;
}
string Pelicula::getSinopsis(){
    return this->sinopsis;    
}
void Sistema::eliminarPelicula(string titulo){
    // Corresponde al caso de uso eliminar pelicula
    IKey clave = new KeyString(titulo);
    Pelicula *p;
    p = (Pelicula *) Pelicula->find(clave);
    Pelicula->remove(p);
    delete p;
    delete clave;       
}
DtPelicula Sistema::seleccionarPelicula(string titulo){
    //Corresponde al caso de uso Ver informacion de pelicula
    IKey clave = new KeyString(titulo);
    DtPelicula *p;
    p = (DtPelicula *) Pelicula->find(clave);

    return p;
}

//eliminarPelicula()

