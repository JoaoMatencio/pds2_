#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

typedef struct periodoAutorizado {
    bool madrugada = false; //00:00 às 05:59
    bool manha = false;     //06:00 às 11:59
    bool tarde = false;     //12:00 às 17:59
    bool noite = false;     //18:00 às 23:59
} periodoAutorizado;


typedef struct autorizacaoCompleta {

    int diaSemana;
    periodoAutorizado periodo;

} autorizacaoCompleta;


class Date {
    private:
    
        //Struct que contem os períodos de autorização
        //para um determinado dia da semana.
        autorizacaoCompleta _aC;

    public:
        Date();
        autorizacaoCompleta& get_aC();
        void set_aC_diaSemana(int);
        void set_aC(int, int);
        void configuraAutorizacao();
};


#endif // DATE_HPP