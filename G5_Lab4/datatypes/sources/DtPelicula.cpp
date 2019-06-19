#include "../headers/DtPelicula.h"

DtPelicula::DtPelicula(std::string titulo, std::string urlPoster, std::string sinopsis, int puntajePromedio) {
    this->titulo = titulo;
    this->urlPoster = urlPoster;
    this->sinopsis = sinopsis;
    this->puntajePromedio = 0;
}

std::string DtPelicula::getTitulo() {
    return this->titulo;
}

std::string DtPelicula::getUrlPoster() {
    return this->urlPoster;
}

std::string DtPelicula::getSinopsis() {
    return this->sinopsis;
}

int DtPelicula::getPuntajePromedio() {
    return this->puntajePromedio;
}

void DtPelicula::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

void DtPelicula::setUrlPoster(std::string urlPoster) {
    this->urlPoster = urlPoster;
}

void DtPelicula::setSinopsis(std::string sinopsis) {
    this->sinopsis = sinopsis;
}

void DtPelicula::setPuntajePromedio(int puntajePromedio) {
    this->puntajePromedio = puntajePromedio;
}

std::ostream& operator<<(std::ostream &o, DtPelicula* dtP) {
    o<<std::string("Titulo: ") << dtP->getTitulo() << std::string(" - UrlPoster: ") << dtP->getUrlPoster() <<
            std::string(" - Sinopsis: ") << dtP->getSinopsis() << std::string(" - Puntaje Promedio: ") << dtP->getPuntajePromedio() << std::endl;
    return o;
}

DtPelicula::~DtPelicula() {
    
}