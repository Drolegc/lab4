#include "../headers/Credito.h"

Credito::Credito(int asientos, int costoTotal, int porcentajeDescuento, std::string financier,Funcion* f) : Reserva(asientos, costoTotal,f){
    this->asientos = asientos;
    this->costoTotal = costoTotal;
    this->porcentajeDescuento = porcentajeDescuento;
    this->financiera = financiera;
}

std::string Credito::getFinanciera() {
    return this->financiera;
}

int Credito::getPorcentajeDescuento() {
    return this->porcentajeDescuento;
}

void Credito::setFinanciera(std::string financiera) {
    this->financiera = financiera;
}

void Credito::setPorcentajeDescuento(int porcentajeDescuento) {
    this->porcentajeDescuento = porcentajeDescuento;
}

Credito::~Credito() {
    
}