#include "user.hpp"
#include "area.hpp"
#include "permission.hpp"



User& User::inserirPermissoes(){
    
    Permission p;
    int selecao;
    std::string nomeUser;
    std::string senhaUser;
    
    std::cout << "Insira o nome do usuário: " << std::endl;
    std::getline(std::cin, nomeUser);
    this -> usuario = nomeUser;

    std::cout << "Digite a senha para o usuário " << nomeUser << "." << std::endl;
    std::getline(std::cin, senhaUser);
    this -> senha;
    
    std::cout << "Escolha a área a ser configurada para o usuário: " << std::endl;
    _area.imprimirNomeAreasVector();
    
    std::cin >> selecao;

    Date d;

    p.inserirAutorizacao(d);

    _area.set_area(_area.atribuiAreaMap(selecao), p);

}

User& User::criarUsuario(std::string nomeUsuario, std::string senhaUsuario, std::string area, Permission& permissao){
    this -> usuario = nomeUsuario;
    this -> senha = senhaUsuario;
    _area.set_area(area, permissao);
}

std::string User::get_Usuario(){
    return this -> usuario;
}

std::string User::get_Senha(){
    return this -> senha;
}

Area& User::get_Area(){
    return _area;
}



