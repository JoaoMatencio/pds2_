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
    this -> usuario = nomeUsuario;
}



