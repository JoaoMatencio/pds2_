#include <iostream>
#include <vector>
#include "administrator.hpp"

void imprimirUsuariosCadastrados(std::map<std::string, User&>& usuariosConfigurados){
    std::map<std::string, User&>::iterator it;
    int contador = 1;
    for(it = usuariosConfigurados.begin(); it != usuariosConfigurados.end(); it++){
        
        std::cout << contador << " - " << it -> first << std::endl;
        contador += 1;

    }
}

int main(){
    
    Administrator admin;
    std::map<std::string, User&> usuariosConfigurados;
    std::string nomeUsuario = " ";
    std::string senhaUsuario = " ";



    while(1){
        std::cout << "Entre com o seu nome de usuário: " << std::endl;
        std::getline(std::cin, nomeUsuario);
        
        std::cout << "Digite a sua senha: " << std::endl;
        std::cin >> senhaUsuario;

        if (nomeUsuario == admin.get_Nome()){
            if (admin.get_Senha() == senhaUsuario){
                int idOpcao0 = 0;
                std::cout << "Escolha uma das opções abaixo:\n"
                        << "1 - Criar novo usuário.\n"
                        << "2 - Editar usuário já existente.\n"
                        << "3 - Adicionar nova área.\n"
                        << "4 - Editar área existente.\n"
                        << "5 - Alterar nome do Administrador.\n"
                        << "6 - Alterar senha do Administrador.\n";
                        
                    std::cin >> idOpcao0;
                    
                    

                    switch (idOpcao0){
                        
                        case 1: {
                            User usuario;
                            std::string nomeUsuario;
                            std::string senhaUsuario;
                            std::map<std::string, User&>::iterator it;

                            std::cout << "Criar novo usuário." << std::endl;
                            std::cout << "Insira o nome do usuário: " << std::endl;
                            std::getline(std::cin, nomeUsuario);
                            it = usuariosConfigurados.find(nomeUsuario);
                            if (it == usuariosConfigurados.end()){
                                std::cout << "Digite a senha para o usuário " << nomeUsuario << ": " << std::endl;
                                std::getline(std::cin, senhaUsuario);
                                usuario.criarUsuario(nomeUsuario, senhaUsuario);
                                usuario.inserirPermissoes();
                            } else {
                                std::cout << "Nome de usuário já cadastrado." << std::endl;
                            }
                            
                        }
                        
                        case 2: {
                            std::string nomeUsuario;
                            std::map<std::string, User&>::iterator it = usuariosConfigurados.begin();
                            int idUsuario = 0;
                            int idOpcao1 = 0;

                            std::cout << "Editar usuário já existente." << std::endl;
                            imprimirUsuariosCadastrados(usuariosConfigurados);
                            std::cout << "Digite o número do usuário cadastrado: " << std::endl;
                            std::cin >> idUsuario;
                            std::advance(it, idUsuario - 1);
                            
                            std::cout << "Qual configuração deseja alterar do usuário? " << std::endl;
                            std::cout << "1 - Alterar nome do usuário.\n"
                                      << "2 - Adicionar nova área para o usuário.\n"
                                      << "3 - Editar permissão de área cadastrada para o usuário.\n"
                                      << "4 - Remover o usuário.\n";
                            std::cin >> idOpcao1;
                            switch (idOpcao1){
                                case 1: {
                                    std::string nomeUsuario;

                                    std::cout << "Nome atual do usuário: " << it -> second.get_Usuario() << std::endl;
                                    std::cout << "Digite o novo nome para o usuário: " << std::endl;
                                    std::getline(std::cin, nomeUsuario);
                                    it -> second.set_Nome(nomeUsuario);
                                }
                                case 2: {
                                    std::string nomeArea;
                                    int posicaoSelecionada;

                                    std::cout << "Adicionar nova área para o usuário " << it -> first << "." << std::endl;
                                    it -> second.get_Area().imprimirNomeAreasVector(); //Imprime o vetor estático nomeArea da classe Area.
                                    std::cout << "Selecione a área que deseja configurar para o usuário." << std::endl;
                                    std::cin >> posicaoSelecionada;
                                    Permission p;
                                    it -> second.get_Area().set_area(it -> second.get_Area().retornaNomeAreaVector(posicaoSelecionada -1), p);
                                }

                            }
                            
                        }
                        case 3:
                    }
            } else {
                break;
            }

        } else {

        }

        }
        
    }
