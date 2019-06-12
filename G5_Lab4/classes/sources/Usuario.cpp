#include "../headers/Usuario.h"

Usuario::Usuario(std::string nickname, std::string urlImagen, std::string contrasenia) {
    this->nickname = nickname;
    this->urlImagen = urlImagen;
    this->contrasenia = contrasenia;
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

void Usuario::setNickame(std::string nickname) {
    this->nickname = nickname;
}

void Usuario::setContrasenia(std::string contrasenia) {
    this->contrasenia = contrasenia;
}

void Usuario::setUrlImagen(std::string urlImagen) {
    this->urlImagen = urlImagen;
}

Usuario::~Usuario() {
    
}