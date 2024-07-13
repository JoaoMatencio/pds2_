#ifndef PERMISSION_HPP
#define PERMISSION_HPP

#include <string>
#include <map>
#include "date.hpp"

class Permission{

  private:

    std::map<int, Date> autorizacaoSemanal; 
  
  public:

    void inserirAutorizacao(Date&);
    void alterarAcrescentarAutorizacao();
    void imprimirAutorizacoes();
    std::string retornaAutorizacao(bool);
    void autorizaAcesso();
};

#endif // PERMISSION_HPP