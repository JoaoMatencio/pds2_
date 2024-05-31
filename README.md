#pragma once
#include <string>
#include <vector>

class Usuarios {
public:
    struct Usuario {
        int UserID;
        std::string nome;
        std::vector<std::string> areasPermissao;
    };
    std::vector<Usuario>& getListaUsuarios();
private:
    void adicionarUsuario(int UserID, const std::string& nome, const std::vector<std::string>& areasPermissao);
    void removerUsuario(int UserID);
    std::vector<Usuario> listaUsuarios;
};
