#include "../headers/DtFecha.h"

DtFecha::DtFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
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

DtFecha::~DtFecha() {
    
}