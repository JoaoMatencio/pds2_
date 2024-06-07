#ifndef STATUS_HPP
#define STATUS_HPP

#include <string>

struct Status {
    // Atributos
    bool portaAberta;

    // Construtor
    Status(bool portaAbertaInicial = false);

    // Métodos
    void escreverLog(const std::string& mensagem) const;
    std::string lerLog() const;
    void modificarLog(const std::string& novaMensagem);
    bool retornarStatus() const;

private:
    std::string log;
};

#endif // STATUS_HPP
