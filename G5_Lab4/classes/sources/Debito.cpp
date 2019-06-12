#include "../headers/Debito.h"

Debito::Debito(int asientos, int costoTotal, std::string bancoEmisor) {
    this->asientos = asientos;
    this->costoTotal = costoTotal;
    this->bancoEmisor = bancoEmisor;
}

std::string Debito::getBancoEmisor() {
    return this->bancoEmisor;
}

void Debito::setBancoEmisor(std::string bancoEmisor) {
    this->bancoEmisor = bancoEmisor;
}

Debito::~Debito() {
    
}