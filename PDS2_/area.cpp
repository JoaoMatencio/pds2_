#include "area.hpp"
#include "permission.hpp"


std::vector<std::string> Area::nomeArea = {"Jardim", "Piscina", "Área de Serviço", "Salão de Festas", "Cozinha", "Área Íntima", "Quarto do Pânico"};

void Area::incluirAreaVector(){
    bool adicionaNovaArea = true;
    char escolha = ' ';

    while (adicionaNovaArea){

        std::cout << "Áreas já criadas: " << std::endl;
        imprimirNomeAreasVector();
        std::cout << "Insira o nome da nova área: " << std::endl;
        std::string novaArea = " ";
        std::getline(std::cin, novaArea);
        Area::nomeArea.push_back(novaArea);
        std::cout << "Área adicionada com sucesso." << std::endl;
        imprimirNomeAreasVector();
        std::cout << "Deseja adicionar nova área ao programa? (S/N)" << std::endl;
        std::cin >> escolha;
        
        if(escolha == 's' or escolha == 'S'){
            adicionaNovaArea = true;
        } else {
            adicionaNovaArea = false;
        }
    }
}

void Area::removerAreaVector(){
    int idArea;
    std::cout << "Escolha a ID da área que deseja remover: " << std::endl;
    imprimirNomeAreasVector();
    std::cin >> idArea;
    Area::nomeArea.erase(Area::nomeArea.begin()-1);
}

void Area::imprimirNomeAreasVector(){
    
    int qteAreas = nomeArea.size();
    for(int i = 0; i < qteAreas; i++){
        std::cout << "Área " << i + 1 << ": " << Area::nomeArea[i] << "." << std::endl;
    }
}


std::string Area::retornaNomeAreaVector(int posicaoSelecionada){
    return Area::nomeArea[posicaoSelecionada];
}

void Area::editarAreaVector(){
    
    int idArea;
    std::string confirmaNome;
    std::cout << "Qual área deseja editar? " << std::endl;
    imprimirNomeAreasVector();
    std::cin >> idArea;
    std::cout << "Digite o novo nome para a área: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, Area::nomeArea[idArea]);
    std::cout << "Confirma o novo nome da área? " << Area::nomeArea[idArea] << std::endl;
    std::cout << "Digite S parar Sim ou N para Não:" << std::endl;
    std::cin >> confirmaNome;
    
    while (confirmaNome == "N" or confirmaNome == "n"){
        std::cout << "Digite o novo nome para a área: " << std::endl;
        std::getline(std::cin, Area::nomeArea[idArea]);
        std::cout << "Confirma o novo nome da área? " << Area::nomeArea[idArea] << std::endl;
        std::cout << "Digite S parar Sim ou N para Não:" << std::endl;
        std::cin >> confirmaNome;
    }
    
    std::cout << "Novo nome salvo com sucesso." << std::endl;
    std::cin.ignore();
}

std::string Area::atribuiAreaMap(int selecao){
    return Area::nomeArea[selecao - 1];
}

void Area::set_area(std::string nomeArea, Permission& permissao){
    areasPermissoes.insert({nomeArea, permissao});
}

void Area::imprimirAreas(){
    std::map<std::string, Permission>::iterator it;
    int idArea = 1;
    for(it = areasPermissoes.begin(); it != areasPermissoes.end(); it++){
        std::cout << idArea << " - " << it -> first << std::endl;
        idArea += 1;
    }
}

void Area::editarAutorizacoesArea(){
    std::map<std::string, Permission>::iterator it;
    it = areasPermissoes.begin();
    int selecaoArea = 0;
    std::cout << "Selecione a área desejada: " << std::endl;
    imprimirAreas();
    std::cin >> selecaoArea;
    std::advance(it, selecaoArea -1);
    it -> second.alterarAcrescentarAutorizacao();
}

std::map<std::string, Permission> Area::get_areasPermissoes(){
    return this -> areasPermissoes;
}

void Area::adicionarNovaArea() {
    Area a;
    std::string novaArea;
    std::cout << "Adicionar nova área: " << std::endl;
    std::getline(std::cin, novaArea);
}

void Area::editarArea() {
    Area a;
    a.editarAreaVector();
}