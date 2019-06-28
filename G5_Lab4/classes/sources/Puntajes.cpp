#include "../headers/Puntajes.h"

Puntajes::Puntajes(int numero,Usuario* usuario){
    this->puntaje = numero;
    this->usuario = usuario;
}
int Puntajes::getPuntaje(){
    return this->puntaje;
}
Usuario* Puntajes::getUsuario(){
    return this->usuario;
}
Puntajes::~Puntajes(){

}