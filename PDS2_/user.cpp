#include "user.hpp"
#include "area.hpp"
#include <iostream>

User::User(){
    usuario = " ";
    senha = " ";
}

void User::inserirPermissoes(){
    
    Permission p;
    int selecao;
    
    std::cout << "Escolha a área a ser configurada para o usuário: " << std::endl;
    _area.imprimirNomeAreasVector();
    
    std::cin >> selecao;

    Date d;

    p.inserirAutorizacao(d);

    _area.set_area(_area.atribuiAreaMap(selecao), p); //Insere os parâmetros configurados no map areasPermissoes.

}

void User::criarUsuario(std::string nomeUsuario, std::string senhaUsuario){
    this -> usuario = nomeUsuario;
    this -> senha = senhaUsuario;
}

std::string User::get_Nome(){
    return this -> usuario;
}

std::string User::get_Senha(){
    return this -> senha;
}

Area& User::get_Area(){
    return _area;
}

void User::set_Nome(std::string nomeUsuario){
    usuario = nomeUsuario;
}

void User::switchCaseUser(int idOpcao0){
    std::string senha;
    switch (idOpcao0) {
        case 1: {
            std::map<std::string, Permission>::iterator it;
            int selecao = 0;
            std::cout << "Áreas permitidas: " << std::endl;
            _area.imprimirAreas();
            std::cout << "Selecione uma área para visualizar as suas permissões." << std::endl;
            std::cin >> selecao;
            it = _area.get_areasPermissoes().begin();
            std::advance(it, selecao - 1);
            it -> second.imprimirAutorizacoes();
            std::cin.ignore();
            break;
        }
        case 2: {
            std::string novaSenha;
            std::cout << "Digite a nova senha: " << std::endl;
            std::getline(std::cin, novaSenha);
            std::cin.ignore();
            senha = novaSenha;
            break;
        }
        default: {
            std::cout << "Opção inválida." << std::endl;
            break;
        }
    }
}