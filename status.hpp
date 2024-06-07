#ifndef STATUS_HPP
#define STATUS_HPP

#include <string>

class Status {
private:
    bool portaAberta;
    std::string log;

public:
    // Construtor
    Status();

    // Métodos
    void escreverLog(const std::string &mensagem);
    std::string lerLog() const;
    void modificarLog(const std::string &novoLog);
    bool retornarStatus() const;

    // Métodos auxiliares
    void abrirPorta();
    void fecharPorta();
};

#endif // STATUS_HPP
