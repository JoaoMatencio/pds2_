#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"

int main() {
    Usuarios usuarios;

    int UserID;
    std::string nome;
    std::vector<std::string> areasPermissao;

    std::cout << "Digite o UserID do novo usuario: ";
    std::cin >> UserID;

    std::cout << "Digite o nome do novo usuario: ";
    std::cin >> nome;

    std::cout << "Digite as areas de permissao do novo usuario (digite 'fim' para parar):\n";
    std::string area;
    while (true) {
        std::cin >> area;
        if (area == "fim") {
            break;
        }
        areasPermissao.push_back(area);
    }

    usuarios.adicionarUsuario(UserID, nome, areasPermissao);

    std::cout << "\nUsuarios cadastrados:\n";
    for (const auto& usuario : usuarios.getListaUsuarios()) {
        std::cout << "UserID: " << usuario.UserID << ", Nome: " << usuario.nome << ", Areas de Permissao: ";
        for (const auto& area : usuario.areasPermissao) {
            std::cout << area << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}