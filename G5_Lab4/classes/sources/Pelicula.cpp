#include "../headers/Pelicula.h"


Pelicula::Pelicula() {
    this->comentarios = new OrderedDictionary();
    this->puntajes = new List();
}

Pelicula::Pelicula(std::string titulo, std::string urlPoster, std::string sinopsis, int puntajePromedio) {
    this->titulo = titulo;
    this->urlPoster = urlPoster;
    this->sinopsis = sinopsis;
    this->puntajePromedio = 0;
    this->comentarios = new OrderedDictionary();
    this->puntajes = new List();
}
void Pelicula::setPuntaje(Puntajes* puntaje){
    this->puntajes->add(puntaje);
}
std::string Pelicula::getTitulo() {
    return this->titulo;
}
IDictionary *Pelicula::getComentarios(){
    return this->comentarios;
}
void Pelicula::setComentario(std::string comentario, Usuario *usuario){
    int numComentario = this->comentarios->getSize() + 1;
    IntKey* KeyComentario = new IntKey (numComentario);
    this->comentarios->add(KeyComentario, new Comentarios(numComentario,comentario,usuario));
}
int Pelicula::getCantidadVecesPuntuada(){
    return this->puntajes->getSize();
}
std::string Pelicula::getUrlPoster() {
    return this->urlPoster;
}

std::string Pelicula::getSinopsis() {
    return this->sinopsis;
}

int Pelicula::getPuntajePromedio() {
  int puntaje = 0;
  IIterator *it = this->puntajes->getIterator();
  int tamanio = this->puntajes->getSize();
  while(it->hasCurrent()){
      Puntajes *p = dynamic_cast<Puntajes*>(it->getCurrent());
      puntaje += p->getPuntaje();
      it->next();
  }
  if(tamanio==0)
    return puntaje;
  return puntaje/tamanio;
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

void Pelicula::listarPeliculas(IDictionary* dicPeliculas) {
    IIterator* it = dicPeliculas->getIterator();
    std::cout << "               PELICULAS" << std::endl;
    std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;
    while (it->hasCurrent()) {
    Pelicula* currentPelicula = dynamic_cast<Pelicula*>(it->getCurrent());
    std::cout << new DtPelicula(currentPelicula->getTitulo(), currentPelicula->getUrlPoster(),
            currentPelicula->getSinopsis(), currentPelicula->getPuntajePromedio());
    std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;

    it->next();
    }
    delete it;
}

Pelicula::~Pelicula() {

}