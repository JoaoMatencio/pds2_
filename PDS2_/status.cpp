#include "status.hpp"
#include <iostream>

// Construtor
Status::Status() : portaAberta(false), log("") {}

// Métodos
void Status::escreverLog(const std::string &mensagem) {
    log += mensagem + "\n";
}

std::string Status::lerLog() const {
    return log;
}

void Status::modificarLog(const std::string &novoLog) {
    log = novoLog;
}

bool Status::retornarStatus() const {
    return portaAberta;
}

// Métodos auxiliares
void Status::abrirPorta() {
    portaAberta = true;
    escreverLog("Porta aberta.");
}

void Status::fecharPorta() {
    portaAberta = false;
    escreverLog("Porta fechada.");
}