#ifndef DATE_HPP
#define DATE_HPP

#include <vector>
#include <iostream>


class Date {
    private:
    int DayCounter;
    int WeekDays;
    int PeriodDays;
    // enum WeekDay {Domingo,Segunda,Terça,Quarta,Quinta,Sexta,Sabado};
    // enum PeriodDay {Madrugada,Manhã,Tarde,Noite}; //00:00-06:00-12:00-18:00-00:00
    //std::vector <WeekDay> AuthorizerWeekdays;
    //std::vector <PeriodDay> AuthorizerPerioddays;

    std::vector <Schedule*> AuthSchedules;


    public:
    void AddSchedule(int, int);
    void HowManyDays ();

};
class Schedule {
    public:
    int WeekDay;
    int PeriodDay;
    //std::vector <int> PeriodDay;
    Schedule(int,int);
};
// Tentar Ideia vetor com 4 posições
// o periodo representa isto
// madrugada = 1 , manha = 2 , tarde=3, noite =4 
// madru+manha = 5 , madru+tarde = 6 , madru+noite =7
// manha+tarde = 8,  manha+noite = 9
// tarde+noite = 10
// mad+man+tar = 11, mad+man+noi = 12 , mad+tar+noit =13
// man+tar+noi = 14 
// tudo = 15

#endif