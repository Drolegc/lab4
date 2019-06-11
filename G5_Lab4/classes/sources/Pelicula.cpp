#include "../headers/Pelicula.h"

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