#include "date.hpp"

/*O construtor Date() atribui à struct autorizacaoCompleta as autorizações 
 *para cada período de um dia conforme especificado no código.
*/ 

Date::Date(){

    std::cout << "Selecione um dia da semana:\n"
                "1 = Domingo \n"
                "2 = Segunda-feira \n"
                "3 = Terça-feira \n"
                "4 = Quarta-feira \n"
                "5 = Quinta-feira \n"
                "6 = Sexta-feira \n"
                "7 = Sábado \n";

    std::cin >> _aC -> diaSemana;

    std::cout << "Selecione a autorização a ser dada ao usuário no período especificado:\n"
                "0 = Permissão Negada\n"
                "1 = Permissão Concedida\n";
    std::cout << "Autoriza o acesso na madrugada (00:00 às 05:59)?" << std::endl;
    std::cin >> _aC -> periodo.madrugada;
    std::cout << "Autoriza o acesso de manhã (06:00 às 11:59)?" << std::endl;
    std::cin >> _aC -> periodo.manha;
    std::cout << "Autoriza o acesso durante a tarde (12:00 às 17:59)?" << std::endl;
    std::cin >> _aC -> periodo.tarde;
    std::cout << "Autoriza o acesso no período noturno (18:00 às 23:59)?" << std::endl;
    std::cin >> _aC -> periodo.noite;

}

autorizacaoCompleta* Date::get_aC(){
    return _aC;
}

void Date::set_aC(int selecionaPeriodo, int autorizacao){
    
    switch(selecionaPeriodo){
        case 0:
            _aC -> periodo.madrugada = autorizacao;
            break;
        case 1:
            _aC -> periodo.manha = autorizacao;
            break;
        case 2:
            _aC -> periodo.tarde = autorizacao;
            break;
        case 3:
            _aC -> periodo.noite = autorizacao;
            break;
    }

}