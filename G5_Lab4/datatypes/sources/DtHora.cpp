#include "../headers/DtHora.h"

DtHora::DtHora(int hora, int minutos) {
    this->hora = hora;
    this->minutos = minutos;
    
    if(!isValid()) {
        throw std::invalid_argument("Hora Inválida");
    }
}

int DtHora::getHora() {
    return this->hora;
}

int DtHora::getMinutos() {
    return this->minutos;
}

void DtHora::setHora(int hora) {
    this->hora = hora;
}

void DtHora::setMinutos(int minutos) {
    this->minutos = minutos;
}

bool DtHora::isValid() {
    return this->hora >= 00 && this->hora <= 23 &&
            this->minutos >= 00 && this->minutos <= 59;
}



DtHora::~DtHora() {
    
}