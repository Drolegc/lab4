#include "../headers/DtPelicula.h"

DtPelicula::DtPelicula(std::string titulo, std::string urlPoster, std::string sinopsis) {
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
    return this->urlPoster;
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

DtPelicula::~DtPelicula() {
    
}