#include "Date.hpp"

Schedule::Schedule (int _Day, int _Period){

    WeekDay = _Day;
    PeriodDay = _Period;
}

void Date::AddSchedule (int Day ,int Period){

    Schedule* aux = new Schedule(Day, Period);
    AuthSchedules.push_back(aux);
    
}

void Date::HowManyDays (){
    std::cout << "Quantos dias? ";
    std::cin >> DayCounter;
    for (auto i = 0; i < DayCounter; i++){
        int day;
        int period;
        std::cin >> day ;
        std::cout << std::endl;
        std::cin >> period;
        AddSchedule (day, period);
    }


    
}
