#ifndef AREA_HPP
#define AREA_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "date.hpp"
#include "permission.hpp"

class Area {

    private:

        std::map<std::string, Permission&> areasPermissoes;
        static std::vector<std::string> nomeArea;
        
    public:
        
        void incluirAreaVector(std::string);
        void removerAreaVector();
        void editarAreaVector();
        void imprimirNomeAreasVector();
        std::string retornaNomeAreaVector(int);
        std::string atribuiAreaMap(int);
        void set_area(std::string, Permission&);
        
        void imprimirAreas();
        void editarAutorizacoesArea(int);
        std::map<std::string, Permission&>& get_areasPermissoes();
};

#endif

