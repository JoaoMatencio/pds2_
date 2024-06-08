#include "usuarios.hpp"
#include <iostream>

// Adicionar um novo usuário
void Usuarios::adicionarUsuario(int userID, const std::string &nome, const std::map<int, Horarios> &acesso) {
    Usuario novoUsuario;
    novoUsuario.userID = userID;
    novoUsuario.nome = nome;
    novoUsuario.acesso = acesso;
    usuarios.push_back(novoUsuario);
}

// Remover um usuário existente com base no userID
void Usuarios::removerUsuario(int userID) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->userID == userID) {
            usuarios.erase(it);
            break;
        }
    }
}

// Modificar o acesso de um usuário
void Usuarios::atualizarAcessoUsuario(int userID, const std::map<int, Horarios> &novoAcesso) {
    for (auto &usuario : usuarios) {
        if (usuario.userID == userID) {
            usuario.acesso = novoAcesso;
            return;
        }
    }
    std::cout << "Usuário com ID " << userID << " não encontrado." << std::endl;
}