#include "../headers/DtHora.h"

DtHora::DtHora(int hora, int minutos) {
    this->hora = hora;
    this->minutos = minutos;
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