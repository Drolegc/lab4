#include "../headers/Usuario.h"

Usuario::Usuario(std::string nickname, std::string urlImagen, std::string contrasenia, bool isAdmin) {
    this->nickname = nickname;
    this->urlImagen = urlImagen;
    this->contrasenia = contrasenia;
    this->isAdmin = isAdmin;
    //FALTABA INICIALIZAR LA COLECCION
    this->reservas = new List();
}

std::string Usuario::getNickname() {
    return this->nickname;
}

std::string Usuario::getContrasenia() {
    return this->contrasenia;
}

std::string Usuario::getUrlImagen() {
    return this->urlImagen;
}

ICollection* Usuario::getReservas(){
    ICollection* dtr = new List();
    IIterator* it = reservas->getIterator();

    while (it->hasCurrent())
    {
        Reserva* r = dynamic_cast<Reserva*>(it->getCurrent());
        if(dynamic_cast<Debito*>(r)){
            dtr->add(dynamic_cast<Debito*>(r));
        }else{
            dtr->add(dynamic_cast<Credito*>(r));
        }
        it->next();
    }
    return dtr;
    
}

bool Usuario::getIsAdmin() {
    return this->isAdmin;
}

void Usuario::setNickame(std::string nickname) {
    this->nickname = nickname;
}

void Usuario::setContrasenia(std::string contrasenia) {
    this->contrasenia = contrasenia;
}

void Usuario::setUrlImagen(std::string urlImagen) {
    this->urlImagen = urlImagen;
}

void Usuario::setIsAdmin(bool estado) {
    this->isAdmin = estado;
}

void Usuario::setReserva(ICollectible* r){
    reservas->add(r);
}


Usuario::~Usuario() {
    
}