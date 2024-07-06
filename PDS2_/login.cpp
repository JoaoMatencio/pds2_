#include "login.hpp"
#include "administrator.hpp"
#include "user.hpp"
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

bool isUser(const std::string& nomeUsuario, const std::string& senhaUsuario){
    User user;
    if (user.get_Nome() == nomeUsuario && user.get_Senha() == senhaUsuario){
        return true;
    }
    return false;
}

int getOption() {
    int idOpcao0;
    std::cout << "Escolha uma das opções abaixo:\n"
              << "1 - Criar novo usuário.\n"
              << "2 - Editar usuário já existente.\n"
              << "3 - Adicionar nova área.\n"
              << "4 - Editar área existente.\n"
              << "5 - Alterar credenciais do Administrador.\n";
    std::cin >> idOpcao0;
    std::cin.ignore();
    return idOpcao0;
}

int getOptionUser() {
    int idOpcao0;
    std::cout << "Escolha uma das opções abaixo:\n"
              << "1 - Visualizar áreas permitidas.\n"
              << "2 - Alterar senha.\n";
    std::cin >> idOpcao0;
    std::cin.ignore();
    return idOpcao0;
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