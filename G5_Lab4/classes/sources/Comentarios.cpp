#include "../headers/Comentarios.h"

Comentarios::Comentarios(int numero, std::string comentario){
    this->comentarios = new OrderedDictionary();
    this->numero = numero;
    this->comentario = comentario;
}

IDictionary* Comentarios::getComentarios(){
    return this->comentarios;
}
std::string Comentarios::getComentario(){
    return this->comentario;
}

void Comentarios::setComentario(std::string comentario){
    this->comentario = comentario;
}
int Comentarios::getNumero(){
    return this->numero;
}
void Comentarios::setComentarios(Comentarios *comentario){

    IntKey* keyCine = new IntKey (comentario->getNumero());
    this->comentarios->add(keyCine,comentario);
}
void Comentarios::listaComentarios(IDictionary *comentarios){
    IIterator* it = comentarios->getIterator();
    while (it->hasCurrent()) {
        Comentarios* currentcomentario =  dynamic_cast<Comentarios*>(it->getCurrent());
        std::cout << currentcomentario->getComentario();
        IDictionary* comentariosDeComentarios = currentcomentario->getComentarios();
        Comentarios::listaComentarios(comentariosDeComentarios);
        it->next();
    }
    delete it;
}
Comentarios::~Comentarios(){

}