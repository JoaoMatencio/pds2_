#include "usuario.hpp"

void Usuarios::adicionarUsuario(int UserID, const std::string& nome, const std::vector<std::string>& areasPermissao) {
    Usuario novoUsuario = {UserID, nome, areasPermissao};
    listaUsuarios.push_back(novoUsuario);
}
void Usuarios::removerUsuario(int UserID) {
    for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); ++it) {
        if (it->UserID == UserID) {
            listaUsuarios.erase(it);
            break;
        }
    }
}
std::vector<Usuarios::Usuario>& Usuarios::getListaUsuarios() {
    return listaUsuarios;
}
