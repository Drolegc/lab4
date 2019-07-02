#include "../headers/DtFecha.h"

DtFecha::DtFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    
    if(!isValid()) {
        throw std::invalid_argument("Fecha Inválida");
    }
}

int DtFecha::getDia() {
    return this->dia;
}

int DtFecha::getMes() {
    return this->mes;
}

int DtFecha::getAnio() {
    return this->anio;
}

void DtFecha::setDia(int dia) {
    this->dia = dia;
}

void DtFecha::setMes(int mes) {
    this->mes = mes;
}

void DtFecha::setAnio(int anio) {
    this->anio = anio;
}

bool DtFecha::isValid() {
    return this->dia >= 1 && this->dia <= 31 &&
            this->mes >= 1 && this->mes <= 12 &&
            this->anio >= 1900;
}


DtFecha::~DtFecha() {
    
}