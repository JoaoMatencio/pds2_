#ifndef PERMISSION_HPP
#define PERMISSION_HPP

#include <string>
#include <map>
#include "date.hpp"


class Permission{

  private:

    std::map<int, Date&> autorizacaoSemanal;
  
  public:

    void inserirAutorizacao(Date&);
    void alterarAutorizacao();
    void imprimirAutorizacoes();
    std::string retornaAutorizacao(bool);
    std::string autorizaAcesso(User&);
};

#endif