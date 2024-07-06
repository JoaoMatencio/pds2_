#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP

#include "user.hpp"
#include <iostream>
#include <map>

class Administrator {
private:
    std::string nomeAdmin;
    std::string senhaAdmin;

public:
    Administrator();
    std::string get_Nome();
    std::string get_Senha();
    void set_Nome(std::string novoNome);
    void set_Senha(std::string senhaAtual, std::string novaSenha);
    void imprimirUsuariosCadastrados(std::map<std::string, User>& usuariosConfigurados);
    void criarNovoUsuario(std::map<std::string, User>& usuariosConfigurados);
    int getOptions_2();
    void editarUsuario(std::map<std::string, User>& usuariosConfigurados);
    void alterarCredenciaisAdmin();
    void switchCaseAdmin(int idOpcao0, std::map<std::string, User>& usuariosConfigurados);
};

#endif // ADMINISTRATOR_HPP
