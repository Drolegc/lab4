#include "../headers/Pelicula.h"

Pelicula::Pelicula() {
    
}

Pelicula::Pelicula(std::string titulo, std::string urlPoster, std::string sinopsis, int puntajePromedio) {
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
    return this->sinopsis;
}

int Pelicula::getPuntajePromedio() {
    return this->puntajePromedio;
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

void Pelicula::listarPeliculas(IDictionary* dicPeliculas) {
    IIterator* it = dicPeliculas->getIterator();
    while (it->hasCurrent()) {
    Pelicula* currentPelicula = dynamic_cast<Pelicula*>(it->getCurrent());
    std::cout << new DtPelicula(currentPelicula->getTitulo(), currentPelicula->getUrlPoster(),
            currentPelicula->getSinopsis(), currentPelicula->getPuntajePromedio());
    it->next();
    }
    delete it;
}

Pelicula::~Pelicula() {
    
}