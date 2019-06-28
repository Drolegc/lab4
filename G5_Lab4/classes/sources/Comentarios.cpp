#include "../headers/Comentarios.h"

Comentarios::Comentarios(int numero, std::string comentario, Usuario * usuario){
    this->comentarios = new OrderedDictionary();
    this->numero = numero;
    this->comentario = comentario;
    this->usuario = usuario;
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
Usuario* Comentarios::getUsuario(){
    return this->usuario;
}
void Comentarios::setComentarios(std::string comentario, Usuario *usuario){
    int numComentario = this->comentarios->getSize()+1;
    IntKey* KeyComentario = new IntKey (numComentario);
    this->comentarios->add(KeyComentario, new Comentarios(numComentario,comentario, usuario));
}
void Comentarios::listaComentarios(IDictionary *comentarios){
    IIterator* it = comentarios->getIterator();
    while (it->hasCurrent()) {
        Comentarios* currentcomentario =  dynamic_cast<Comentarios*>(it->getCurrent());
        Usuario *u= currentcomentario->getUsuario();
        std::string nickname = u->getNickname();
        std::cout <<currentcomentario->getNumero()<<" - " <<nickname<<" - "<< currentcomentario->getComentario()<<std::endl;
        IDictionary* comentariosDeComentarios = currentcomentario->getComentarios();
        Comentarios::listaComentarios(comentariosDeComentarios);
        it->next();
    }
    delete it;
}
Comentarios::~Comentarios(){

}