#include <iostream>
#include <vector>
#include "administrator.hpp"

int main(){
    
    Administrator admin;
    std::string nomeUsuario = " ";
    std::string senhaUsuario = " ";


    while(1){
        std::cout << "Entre com o seu nome de usuário: " << std::endl;
        std::getline(std::cin, nomeUsuario);
        
        std::cout << "Digite a sua senha: " << std::endl;
        std::cin >> senhaUsuario;

        if (nomeUsuario == admin.get_Nome()){
            if (admin.get_Senha() == senhaUsuario){
                int opcao = 0;
                std::cout << "Escolha uma das opções abaixo:\n"
                        << "1 - Criar novo usuário.\n"
                        << "2 - Editar usuário já existente.\n"
                        << "3 - Remover usuário.\n"
                        << "4 - Adicionar nova área.\n"
                        << "5 - Editar área existente.\n"
                        << "6 - Alterar nome do Administrador.\n"
                        << "7 - Alterar senha do Administrador.\n";
                        
                    std::cin >> opcao;
                    
                    

                    switch (opcao){
                        
                        case 1: {
                            User usuario;
                            std::cout << "Criar novo usuário." << std::endl;
                            usuario.inserirPermissoes();}
                        case 2:
                        case 3:
                    }
            } else {
                break;
            }

        } else {

        }

        }
        
    }


/*Observa-se que o administrador possui um Map <nomeUsuario, Area>
Ambos devem vir de um objeto User previamente criado.
Perguntas:
    1. Em que momento esse objeto é criado?
    2. Deve-se usar um método. Ele estará dentro da classe User. Ele deve retornar um User&
    3. O administrador poderá usar esse método.
    4. Criado o usuário, ele deve ser alocado dentro de um std::vector<User&> Usuários.
*/