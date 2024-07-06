#include "date.hpp"

Date::Date(){

    _Ac.diaSemana = 88;
    _Ac.periodo.madrugada = false;
    _Ac.periodo.manha = false;
    _Ac.periodo.tarde = false;
    _Ac.periodo.noite = false;

}

autorizacaoCompleta& Date::getAc(){
    return _Ac;
}

void Date::setAc(int selecionaPeriodo, int autorizacao){
    
    switch(selecionaPeriodo){
        case 0:
            _Ac.periodo.madrugada = autorizacao;
            break;
        case 1:
            _Ac.periodo.manha = autorizacao;
            break;
        case 2:
            _Ac.periodo.tarde = autorizacao;
            break;
        case 3:
            _Ac.periodo.noite = autorizacao;
            break;
    }

}


void Date::configuraAutorizacao(){

    std::cout << "Selecione um dia da semana:\n"
                "1 = Domingo \n"
                "2 = Segunda-feira \n"
                "3 = Terça-feira \n"
                "4 = Quarta-feira \n"
                "5 = Quinta-feira \n"
                "6 = Sexta-feira \n"
                "7 = Sábado \n";

    std::cin >> _Ac.diaSemana;

    std::cout << "Selecione a autorização a ser dada ao usuário no período especificado:\n"
                "0 = Permissão Negada\n"
                "1 = Permissão Concedida\n";
    std::cout << "Autoriza o acesso na madrugada (00:00 às 05:59)?" << std::endl;
    std::cin >> _Ac.periodo.madrugada;
    std::cout << "Autoriza o acesso de manhã (06:00 às 11:59)?" << std::endl;
    std::cin >> _Ac.periodo.manha;
    std::cout << "Autoriza o acesso durante a tarde (12:00 às 17:59)?" << std::endl;
    std::cin >> _Ac.periodo.tarde;
    std::cout << "Autoriza o acesso no período noturno (18:00 às 23:59)?" << std::endl;
    std::cin >> _Ac.periodo.noite;

}