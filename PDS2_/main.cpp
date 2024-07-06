#include "administrator.hpp"
#include "user.hpp"

void imprimirUsuariosCadastrados(std::map<std::string, User&>& usuariosConfigurados){
    std::map<std::string, User&>::iterator it;
    int contador = 1;
    for(it = usuariosConfigurados.begin(); it != usuariosConfigurados.end(); it++){
        
        std::cout << contador << " - " << it -> first << std::endl;
        contador += 1;

    }
}

std :: string getNomeUsuario(std::map<std::string, User&>& usuariosConfigurados, int idUsuario){
    std::map<std::string, User&>::iterator it = usuariosConfigurados.begin();
    std::advance(it, idUsuario - 1);
    return it -> first;
}

std::string getUser() {
    std::string nomeUsuario = " ";
    std::cout << "Entre com o nome de usuário que deseja logar: " << std::endl;
    std::getline(std::cin, nomeUsuario);
    return nomeUsuario;
}

std::string getSenha() {
    std::string senhaUsuario = " ";
    std::cout << "Digite a sua senha para logar: " << std::endl;
    std::cin >> senhaUsuario;
    return senhaUsuario;
}

bool isAdmin(std::string nomeUsuario, std::string senhaUsuario){
    Administrator admin;
    if (nomeUsuario == admin.get_Nome() && senhaUsuario == admin.get_Senha()){
        return true;
    } else {
        std::cout << "Senha do administrador incorreta." << std::endl;
        return false;
    }
}

int getOption(){
    int idOpcao0 = 0;
    std::cout << "Escolha uma das opções abaixo:\n"
                    << "1 - Criar novo usuário.\n"
                    << "2 - Editar usuário já existente.\n"
                    << "3 - Adicionar nova área.\n"
                    << "4 - Editar área existente.\n"
                    << "5 - Alterar credenciais do Administrador.\n";
                    
    std::cin >> idOpcao0;
    return idOpcao0;
}

int getOptions_2(){
    int idOpcao1 = 0;
    std::cout << "Qual configuração deseja alterar do usuário? " << std::endl;
    std::cout << "1 - Alterar nome do usuário.\n"
                << "2 - Adicionar nova área para o usuário.\n"
                << "3 - Editar permissão de área cadastrada para o usuário.\n"
                << "4 - Remover o usuário.\n";

    std::cin >> idOpcao1;
    return idOpcao1;
}

void criarNovoUsuario(std::map<std::string, User&>& usuariosConfigurados) {
    User usuario;
    std::string nomeUsuario = " ";
    std::string senhaUsuario = " ";
    std::map<std::string, User&>::iterator it;

    std::cout << "Criar novo usuário." << std::endl;
    std::cout << "Insira o nome do novo usuário: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nomeUsuario);
    it = usuariosConfigurados.find(nomeUsuario);
    if (it == usuariosConfigurados.end()) {
        std::cout << "Digite a senha para o novo usuário " << nomeUsuario << ": " << std::endl;
        std::getline(std::cin, senhaUsuario);
        usuario.criarUsuario(nomeUsuario, senhaUsuario);
        usuario.inserirPermissoes();
        usuariosConfigurados.insert(std::pair<std::string, User&>(usuario.get_Nome(), usuario));
    } else {
        std::cout << "Nome de usuário já cadastrado." << std::endl;
    }
    std::cin.ignore();
}

void editarUsuario() {
    int idOpcao1 = getOptions_2();
    std::string nomeUsuario;
    std::map<std::string, User&>::iterator it;
    int idUsuario = 0;
    std::map<std::string, User&> usuariosConfigurados;
 

    std::cout << "Editar usuário já existente." << std::endl;
    imprimirUsuariosCadastrados(usuariosConfigurados);
    std::cout << "Digite o número do usuário cadastrado: " << std::endl;
    std::cin >> idUsuario;
    std::cin.ignore();
    it = usuariosConfigurados.begin();
    std::advance(it, idUsuario - 1);
    
    std::cout << "Qual configuração deseja alterar do usuário? " << std::endl;
    std::cout << "1 - Alterar nome do usuário.\n"
                << "2 - Adicionar nova área para o usuário.\n"
                << "3 - Editar permissão de área cadastrada para o usuário.\n"
                << "4 - Remover o usuário.\n";

    std::cin >> idOpcao1;

    switch (idOpcao1){
        case 1: {
            std::string nomeUsuario = " ";

            std::cout << "Nome atual do usuário: " << it -> second.get_Nome() << std::endl;
            std::cout << "Digite o novo nome para o usuário: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, nomeUsuario);
            it -> second.set_Nome(nomeUsuario);
            break;
        }
        case 2: {
            std::string nomeArea;
            int posicaoSelecionada;

            std::cout << "Adicionar nova área para o usuário " << it -> first << "." << std::endl;
            it -> second.get_Area().imprimirNomeAreasVector(); //Imprime o vetor estático nomeArea da classe Area.
            std::cout << "Selecione a área que deseja configurar para o usuário." << std::endl;
            std::cin >> posicaoSelecionada;
            std::cin.ignore();
            Permission p;
            it -> second.get_Area().set_area(it -> second.get_Area().retornaNomeAreaVector(posicaoSelecionada -1), p);
            break;
        }
        case 3: {
            int areaSelecionada;
            it -> second.get_Area().imprimirAreas();
            std::cout << "Seleciona a área que deseja editar as permissões: " << std::endl;
            std::cin >> areaSelecionada;
            std::cin.ignore();
            it -> second.get_Area().editarAutorizacoesArea(areaSelecionada);
            break;
        }
        case 4: {
            usuariosConfigurados.erase(it);
            break;
        }
    }
}
void adcionarNovaArea(){
    Area a;
    std::string novaArea = " ";
    std::cout << "Adicionar nova área: " << std::endl; //Adiciona nova área ao vector Area::nomeArea;
    std::cin.ignore();
    std::getline(std::cin, novaArea);
    a.incluirAreaVector(novaArea);
}

void editarArea(){
    Area a;
    a.editarAreaVector();
}

void alterarCredenciaisAdmin(){
    Administrator admin;
    std::string novoNome;
    std::string senhaAtual;
    std::string novaSenha;
    std::cout << "Alterar nome do Administrador." << std::endl;
    std::cout << "Nome atual: " << admin.get_Nome();
    std::cout << "Insira o novo nome do Administrador: " << std::endl;
    std::getline(std::cin, novoNome);
    admin.set_Nome(novoNome);
    std::cout << "Insira a senha atual do administrador: " << std::endl;
    std::getline(std::cin, senhaAtual);
    admin.set_Senha(senhaAtual, novaSenha);
}


int main(){
    bool stop = false;

    while(stop == false){

        std::string nomeUsuario = getUser();
        std::string senhaUsuario = getSenha();
        if (isAdmin(nomeUsuario, senhaUsuario)){
            int idOpcao0 = getOption();
            switch (idOpcao0){
                case 1: {
                    criarNovoUsuario(usuariosConfigurados);
                    break;
                }
                case 2: {
                    editarUsuario();
                    break;
                }
                case 3: {
                    adcionarNovaArea();
                    break;
                }
                case 4: {
                    editarArea();
                    break;
                }
                case 5: {
                    alterarCredenciaisAdmin();
                    break;
                }
            }
        } else {
            //Inicio da implementação do código para conferencia de
            //autorizacoes e acessos efetivos.
    }
    }
    }
