#include "../headers/Comentarios.h"
#include "../../libs/manejo_strings.cpp"
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
    int numComentario = this->numero+1;
    while(true){
        if(this->comentarios->find(new IntKey (numComentario))== NULL){
            break;
        }
        numComentario++;
    }
    IntKey* KeyComentario = new IntKey (numComentario);
    this->comentarios->add(KeyComentario, new Comentarios(numComentario,comentario, usuario));
}
void Comentarios::listaComentarios(IDictionary *comentarios, int nivel){
    IIterator* it = comentarios->getIterator();
    std::string espacio = "";
    for(int x=0;x<=nivel;x++){
        espacio +=" ";
    }
    while (it->hasCurrent()) {
        Comentarios* currentcomentario =  dynamic_cast<Comentarios*>(it->getCurrent());
        Usuario *u= currentcomentario->getUsuario();
        std::string nickname = u->getNickname();
        std::cout <<espacio<<"                            " << currentcomentario->getNumero()<<" - " <<nickname<<" - "<< currentcomentario->getComentario()<<std::endl;
        IDictionary* comentariosDeComentarios = currentcomentario->getComentarios();
        Comentarios::listaComentarios(comentariosDeComentarios, nivel+=1);
        it->next();
    }
    delete it;
}
Comentarios * Comentarios::buscarComentario(IDictionary* comentarios, std::string idComentario){
    if(strpos(idComentario,".")){
        vector<std::string>parametros = split(idComentario,".");
        Comentarios* com = NULL;
        int tamanio = parametros.size();
        for(int x=0; x<tamanio;x++){
            if(x == 0){
                com = (Comentarios*)(comentarios->find(new IntKey (std::stoi(parametros[x]))));
            }else{
                IDictionary * coments = com->getComentarios();
                com = (Comentarios*)(coments->find(new IntKey (std::stoi(parametros[x]))));
            }
        }
        return com;
    }else{
        IntKey * key = new IntKey(stoi(idComentario));
        Comentarios * comentario = (Comentarios*)comentarios->find(key);
        return comentario;
    }
}
Comentarios::~Comentarios(){

}
