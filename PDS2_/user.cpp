#include "user.hpp"

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

    _area.setArea(_area.atribuiAreaMap(selecao), p); //Insere os parâmetros configurados no map areasPermissoes.

}

void User::criarUsuario(std::string nomeUsuario, std::string senhaUsuario){
    this -> usuario = nomeUsuario;
    this -> senha = senhaUsuario;
}

std::string User::getNome(){
    return this -> usuario;
}

std::string User::getSenha(){
    return this -> senha;
}

Area& User::getArea(){
    return _area;
}

void User::setNome(std::string nomeUsuario){
    this -> usuario = nomeUsuario;
}



