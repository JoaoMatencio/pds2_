#include "administrator.hpp"
#include "area.hpp"
#include <iostream>

Administrator::Administrator() {
    nomeAdmin = "admin";
    senhaAdmin = "admin";
}

std::string Administrator::get_Nome() {
    return nomeAdmin;
}

std::string Administrator::get_Senha() {
    return senhaAdmin;
}

void Administrator::set_Nome(std::string novoNome) {
    nomeAdmin = novoNome;
}

void Administrator::set_Senha(std::string senhaAtual) {
    if (senhaAdmin == senhaAtual) {
        std::cout << "Insira a nova senha: " << std::endl;
        std::string novaSenha = " ";
        std::getline(std::cin, novaSenha);
        senhaAdmin = novaSenha;
        std::cout << "Senha alterada com sucesso." << std::endl;
    } else {
        int contador = 0;
        int tentativas = 4;

        while (contador < 3) {
            contador += 1;
            tentativas = tentativas - contador;

            std::cout << "Senha incorreta.\n"
                      << "Tentativas restantes: " << tentativas << ".\n"
                      << "Digite novamente a senha atual do administrador: " << std::endl;

            std::getline(std::cin, senhaAtual);

            if (senhaAdmin == senhaAtual) {
                std::cout << "Insira a nova senha: " << std::endl;
                std::string novaSenha = " ";
                std::getline(std::cin, novaSenha);
                senhaAdmin = novaSenha;
                std::cout << "Senha alterada com sucesso." << std::endl;
                contador = 3;
            }
        }
    }
}

bool Administrator::isAdmin(const std::string& nomeUsuario, const std::string& senhaUsuario) {

    if (nomeUsuario == nomeAdmin && senhaUsuario == senhaAdmin) {
        return true;
    } else {
        std::cout << "Senha do administrador incorreta." << std::endl;
        return false;
    }
}

void Administrator::imprimirUsuariosCadastrados(std::map<std::string, User>& usuariosConfigurados) {
    int contador = 1;
    for (auto& it : usuariosConfigurados) {
        std::cout << contador << " - " << it.first << std::endl;
        contador += 1;
    }
}

void Administrator::criarNovoUsuario(std::map<std::string, User>& usuariosConfigurados) {
    User usuario;
    std::string nomeUsuario;
    std::string senhaUsuario;

    std::cout << "Criar novo usuário." << std::endl;
    std::cout << "Insira o nome do novo usuário: " << std::endl;
    std::getline(std::cin, nomeUsuario);

    if (usuariosConfigurados.find(nomeUsuario) == usuariosConfigurados.end()) {
        std::cout << "Digite a senha para o novo usuário " << nomeUsuario << ": " << std::endl;
        std::getline(std::cin, senhaUsuario);
        usuario.criarUsuario(nomeUsuario, senhaUsuario);
        usuario.inserirPermissoes();
        usuariosConfigurados.insert({usuario.get_Nome(), usuario});
        std::cin.ignore();
    } else {
        std::cout << "Nome de usuário já cadastrado." << std::endl;
    }
}

int Administrator::getOptions_2() {
    int idOpcao1;
    std::cout << "Qual configuração deseja alterar do usuário? " << std::endl;
    std::cout << "1 - Alterar nome do usuário.\n"
              << "2 - Adicionar nova área para o usuário.\n"
              << "3 - Editar permissão de área cadastrada para o usuário.\n"
              << "4 - Remover o usuário.\n";
    std::cin >> idOpcao1;
    std::cin.ignore();
    return idOpcao1;
}

void Administrator::editarUsuario(std::map<std::string, User>& usuariosConfigurados) {
    int idOpcao1 = getOptions_2();
    int idUsuario;

    std::cout << "Editar usuário já existente." << std::endl;
    imprimirUsuariosCadastrados(usuariosConfigurados);
    std::cout << "Digite o número do usuário cadastrado: " << std::endl;
    std::cin >> idUsuario;
    std::cin.ignore();

    auto it = usuariosConfigurados.begin();
    std::advance(it, idUsuario - 1);

    switch (idOpcao1) {
        case 1: {
            std::string nomeUsuario;
            std::cout << "Nome atual do usuário: " << it->second.get_Nome() << std::endl;
            std::cout << "Digite o novo nome para o usuário: " << std::endl;
            std::getline(std::cin, nomeUsuario);
            it->second.set_Nome(nomeUsuario);
            usuariosConfigurados[nomeUsuario] = it -> second;
            usuariosConfigurados.erase(it);

            break;
        }
        case 2: {
            std::string nomeArea;
            int posicaoSelecionada;

            std::cout << "Adicionar nova área para o usuário " << it->first << "." << std::endl;
            it->second.get_Area().imprimirNomeAreasVector();
            std::cout << "Selecione a área que deseja configurar para o usuário." << std::endl;
            std::cin >> posicaoSelecionada;
            std::cin.ignore();
            Permission p;
            it->second.get_Area().set_area(it->second.get_Area().retornaNomeAreaVector(posicaoSelecionada - 1), p);
            break;
        }
        case 3: {
            int areaSelecionada;
            it->second.get_Area().imprimirAreas();
            std::cout << "Seleciona a área que deseja editar as permissões: " << std::endl;
            std::cin >> areaSelecionada;
            std::cin.ignore();
            it->second.get_Area().editarAutorizacoesArea(areaSelecionada);
            break;
        }
        case 4: {
            usuariosConfigurados.erase(it);
            break;
        }
    }
}

void Administrator::alterarCredenciaisAdmin() {
    std::string novoNome = " ";
    std::string senhaAtual = " ";
    std::string novaSenha = " ";

    std::cout << "Alterar nome do Administrador." << std::endl;
    std::cout << "Nome atual: " << get_Nome() << std::endl;
    std::cout << "Insira o novo nome do Administrador: " << std::endl;
    std::getline(std::cin, novoNome);
    set_Nome(novoNome);

    std::cout << "Insira a senha atual do administrador: " << std::endl;
    std::getline(std::cin, senhaAtual);
    set_Senha(senhaAtual);
    
}

void Administrator::switchCaseAdmin(int idOpcao0, std::map<std::string, User>& usuariosConfigurados) {
    Area area;
    switch (idOpcao0) {
        case 1:
            criarNovoUsuario(usuariosConfigurados);
            break;
        case 2:
            editarUsuario(usuariosConfigurados);
            break;
        case 3:
            area.adicionarNovaArea();
            break;
        case 4:
            area.editarArea();
            break;
        case 5:
            alterarCredenciaisAdmin();
            break;
        default:
            std::cout << "Opção inválida." << std::endl;
            break;
    }
}
