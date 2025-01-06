#include "../include/passenger.h"
#include <iostream>

using namespace std;

Passenger::Passenger(pair<string, string> _name, int _age) : name(_name), age(_age) {}
Passenger::~Passenger() {};

TicketPassenger::
    TicketPassenger(pair<string, string> _name, int _age, string _date, double _ticket_price) : Passenger(_name, _age)
{
    date = _date;
    ticket_price = _ticket_price;
}

void TicketPassenger::getInfo() const
{
    for (int i = 0; i < 15; i++)
        cout << "-";
    cout << endl
         << "Ticket Passenger" << endl;
    cout << name.first << ' ' << name.second << ' ' << age << endl;

    cout << "Ticket Price is " << ticket_price << endl;
    cout << "Date of journey is " << date << endl;
    for (int i = 0; i < 15; i++)
        cout << "-";
}

PreferencialPassenger::PreferencialPassenger(pair<string, string> _name, int _age, string _pref_type, string _range)
    : Passenger(_name, _age)
{
    prefrencion_type = _pref_type;
    range_of_access = _range;
}

void PreferencialPassenger::getInfo() const
{
    for (int i = 0; i < 15; i++)
        cout << "-";
    cout << endl
         << "Preferencial Passenger" << endl;
    cout << name.first << ' ' << name.second << ' ' << age << endl;

    cout << "Preferencion Type is " << prefrencion_type << endl;
    cout << "Range of Access is " << range_of_access << endl;
    for (int i = 0; i < 15; i++)
        cout << "-";
}

MembershipPassenger::MembershipPassenger(pair<string, string> _name, int _age, string _price, string _type) : Passenger(_name, _age)
{
    price = _price;
    type = _type;
}
void MembershipPassenger::getInfo() const
{
    for (int i = 0; i < 15; i++)
        cout << "-";
    cout << endl
         << "Membership Passenger" << endl;
    cout << name.first << ' ' << name.second << ' ' << age << endl;

    cout << "Membership type is " << type << endl;
    cout << "Price is " << price << endl;
    for (int i = 0; i < 15; i++)
        cout << "-";
}

FareDodgerPassenger::FareDodgerPassenger(pair<string, string> _name, int _age, bool _is_wasted) : Passenger(_name, _age)
{
    is_wasted = _is_wasted;
}
void FareDodgerPassenger::getInfo() const
{
    for (int i = 0; i < 15; i++)
        cout << "-";
    cout << endl
         << "Fare Dodger Passenger" << endl;
    cout << name.first << ' ' << name.second << ' ' << age << endl;

    cout << "Is Wasted: " << is_wasted << endl;
    for (int i = 0; i < 15; i++)
        cout << "-";
}

Passenger *PassengerList::operator[](size_t index)
{
    if (index >= size)
        throw out_of_range("Out of range of passengers");
    return list[index];
}

PassengerList::PassengerList(size_t size)
{
    list = new Passenger *[size];
    for (size_t i = 0; i < size; i++)
    {
        list[i] = nullptr;
    }
}

PassengerList::~PassengerList()
{
    for (size_t i = 0; i < size; i++)
    {
        delete list[i];
    }
    delete[] list;
}

void PassengerList::pushback(Passenger *p)
{
    if (freeslot == size)
    {
        throw "Have no free slot!";
    }
    else
    {
        list[freeslot] = p;
        freeslot++;
    }
}

void PassengerList::erase(int index)
{
    if (list[index] == nullptr)
    {
        throw "Passenger does not exist";
    }
    else
    {
        list[index] = nullptr;
    }
}