#include "../headers/Pelicula.h"

Pelicula::Pelicula() {
    this->comentarios = new OrderedDictionary();
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
IDictionary *Pelicula::getComentarios(){
    return this->comentarios;
}
void Pelicula::setComentario(std::string comentario){
    IIterator *it  = this->comentarios->getIterator();
    int numComentario = 0;
    while (it->hasCurrent()) {
        numComentario++;
        it->next();
    }
    numComentario++;
    IntKey* KeyComentario = new IntKey (numComentario);
    this->comentarios->add(KeyComentario, new Comentarios(numComentario,comentario));
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