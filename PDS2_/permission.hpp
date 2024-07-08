#ifndef PERMISSION_HPP
#define PERMISSION_HPP

#include <string>
#include <map>
#include "date.hpp"

class Permission{

  private:

    //TAD que relaciona o dia da semana (tipo int) 
    //com a autorização para todos os períodos desse dia (tipo Date).
    std::map<int, Date&> autorizacaoSemanal; 
  
  public:

    void inserirAutorizacao(Date&);
    void alterarAcrescentarAutorizacao();
    void imprimirAutorizacoes();
    std::string retornaAutorizacao(bool);
    void autorizaAcesso();
};

#endif // PERMISSION_HPP