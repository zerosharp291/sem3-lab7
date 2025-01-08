#include <iostream>
#include "passenger.h"

using namespace std;

void get_spacebar()
{
    for (int i = 0; i < 3; i++)
        cout << endl;
}

int main()
{

    Passenger *p1 = new TicketPassenger(make_pair("John", "Snow"), 33, "today", 20.12);
    Passenger *p2 = new TicketPassenger(make_pair("James", "Bond"), 47, "1953", 33.33);
    Passenger *p3 = new PreferencialPassenger(make_pair("Jury", "Bury"), 12, "school", "schooltime", 9.99);
    Passenger *p4 = new PreferencialPassenger(make_pair("Alex", "Samoylov"), 12, "pensioner", "everytime", 9.99);
    Passenger *p5 = new MembershipPassenger(make_pair("Nura", "Nurina"), 58, 100, "unlimited");
    Passenger *p6 = new MembershipPassenger(make_pair("Semyon", "Pechkin"), 60, 70, "limited 65");
    Passenger *p7 = new FareDodgerPassenger(make_pair("Andrew", "Zaytsev"), 21, false);
    Passenger *p8 = new FareDodgerPassenger(make_pair("Michael", "Zaytsev"), 18, true);

    PassengerList l1(8);

    l1.pushback(p1);
    l1.pushback(p2);
    l1.pushback(p3);
    l1.pushback(p4);
    l1.pushback(p5);
    l1.pushback(p6);
    l1.pushback(p7);
    l1.pushback(p8);

    l1.get_info();

    l1.erase(0);
    get_spacebar();
    l1.get_info();

    Passenger *p9 = new TicketPassenger(make_pair("Harvey", "Branson"), 41, "now", 20.12);

    l1.emplace(0, p9);

    get_spacebar();
    l1.get_info();

    return 0;
}