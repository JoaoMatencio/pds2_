#include "administrator.hpp"


Administrator::Administrator(){
    nomeAdmin = "admin";
    senhaAdmin = "admin";
}

std::string Administrator::getNome(){
    return nomeAdmin;
}

std::string Administrator::getSenha(){
    return senhaAdmin;
}

void Administrator::setNome(std::string novoNome){
    this -> nomeAdmin = novoNome;
}

void Administrator::setSenha(std::string senhaAtual, std::string novaSenha){
    if (senhaAtual == senhaAdmin){

        std::cout << "Insira a nova senha: " << std::endl;
        std::getline(std::cin, novaSenha);
        this -> senhaAdmin = novaSenha;
        std::cout << "Senha alterada com sucesso." << std::endl;

    } else {

        int contador = 0;
        int tentativas = 4;

        while (contador < 3){
            
            contador += 1;
            tentativas = tentativas - contador;

            std::cout << "Senha incorreta.\n"
                      << "Tentativas restantes: " << tentativas << ".\n" 
                      <<  "Digite novamente a senha atual do administrador: " << std::endl;
            
            std::getline(std::cin, senhaAtual);

            if (senhaAtual == senhaAdmin){
                std::cout << "Insira a nova senha: " << std::endl;
                std::getline(std::cin, novaSenha);
                this -> senhaAdmin = novaSenha;
                std::cout << "Senha alterada com sucesso." << std::endl;
                contador = 3;
            }
            
        }
    }
    
}



