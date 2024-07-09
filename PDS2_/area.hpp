#ifndef AREA_HPP
#define AREA_HPP

#include <string>
#include <vector>
#include <map>
#include "permission.hpp"

class Area {

private:
    std::map<std::string, Permission> areasPermissoes;
    static std::vector<std::string> nomeArea;

public:
    void incluirAreaVector();
    void removerAreaVector();
    void editarAreaVector();
    void imprimirNomeAreasVector();
    std::string retornaNomeAreaVector(int posicaoSelecionada);
    std::string atribuiAreaMap(int selecao);
    void set_area(std::string nomeArea, Permission& permissao);
    void adicionarNovaArea();
    void editarArea();
    void imprimirAreas();
    void editarAutorizacoesArea();
    std::map<std::string, Permission> get_areasPermissoes();
};

#endif // AREA_HPP