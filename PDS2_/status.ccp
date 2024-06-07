#include "status.hpp"
#include <fstream>
#include <iostream>

// Construtor
Status::Status(bool portaAbertaInicial) : portaAberta(portaAbertaInicial), log("") {}

// Métodos
void Status::escreverLog(const std::string& mensagem) const {
    std::ofstream logFile("status_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << mensagem << std::endl;
        logFile.close();
    } else {
        std::cerr << "Unable to open log file." << std::endl;
    }
}

std::string Status::lerLog() const {
    std::ifstream logFile("status_log.txt");
    std::string line, logContent = "";
    if (logFile.is_open()) {
        while (getline(logFile, line)) {
            logContent += line + "\n";
        }
        logFile.close();
    } else {
        std::cerr << "Unable to open log file." << std::endl;
    }
    return logContent;
}

void Status::modificarLog(const std::string& novaMensagem) {
    log = novaMensagem;
    std::ofstream logFile("status_log.txt");
    if (logFile.is_open()) {
        logFile << log << std::endl;
        logFile.close();
    } else {
        std::cerr << "Unable to open log file." << std::endl;
    }
}

bool Status::retornarStatus() const {
    return portaAberta;
}
