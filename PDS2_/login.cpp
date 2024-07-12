#include "login.hpp"
#include "administrator.hpp"
#include <iostream>

std::string getUser() {
    std::string nomeUsuario;
    std::cout << "Entre com o nome de usuário que deseja logar: " << std::endl;
    std::getline(std::cin, nomeUsuario);
    return nomeUsuario;
}

std::string getSenha() {
    std::string senhaUsuario;
    std::cout << "Digite a sua senha para logar: " << std::endl;
    std::cin >> senhaUsuario;
    std::cin.ignore();
    return senhaUsuario;
}

bool noFindAdmin(const std::string& nomeUsuario, std::map<std::string, User>& usuariosConfigurados){
    std::map<std::string, User>::iterator it;
    it = usuariosConfigurados.find(nomeUsuario);
    if (it == usuariosConfigurados.end()){
        return true;
    } else {
        return false;
    }
}

bool findUser(const std::string& nomeUsuario, const std::string& senhaUsuario, std::map<std::string, User>& usuariosConfigurados){

    std::map<std::string, User>::iterator it;
    it = usuariosConfigurados.find(nomeUsuario);
    if (it != usuariosConfigurados.end() && it -> second.get_Senha() == senhaUsuario){
        return true;
    } else {
        return false;
    }
}

User& returnUser(const std::string& nomeUsuario, std::map<std::string, User>& usuariosConfigurados){
        std::map<std::string, User>::iterator it;
        it = usuariosConfigurados.find(nomeUsuario);
        return it -> second;
}

int getOption() {
    int idOpcao0;
    std::cout << "Escolha uma das opções abaixo:\n"
              << "1 - Criar novo usuário.\n"
              << "2 - Editar usuário já existente.\n"
              << "3 - Adicionar nova área a lista de áreas do programa.\n"
              << "4 - Editar área existente na lista de áreas do programa.\n"
              << "5 - Alterar credenciais do Administrador.\n";
    std::cin >> idOpcao0;
    std::cin.ignore();
    return idOpcao0;
}

int getOptionUser() {
    int idOpcao0;
    std::cout << "Escolha uma das opções abaixo:\n"
              << "1 - Visualizar áreas permitidas e períodos autorizados.\n"
              << "2 - Abrir porta.\n"
              << "3 - Alterar senha.\n";
    std::cin >> idOpcao0;
    std::cin.ignore();
    return idOpcao0;
}

void imprimeUsuariosConfigurados(std::map<std::string, User>& usuariosConfigurados){
    std::map<std::string, User>::iterator it;
    int contador = 1;
    for(it = usuariosConfigurados.begin(); it != usuariosConfigurados.end(); it++){
        std::cout << contador << " - " << it -> first << std::endl;
    }
}

bool stopOrRepeat() {
    std::cout << "Usuário inexistente ou senha incorreta." << std::endl;
    std::cout << "Deseja tentar novamente? (S/N)" << std::endl;
    char resposta;
    std::cin >> resposta;
    if (resposta == 'n' or resposta == 'N') {
        return true;
    }
    return false;
}