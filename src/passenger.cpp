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

void TicketPassenger::get_info() const
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
    cout << endl;
}

double TicketPassenger::get_ticket_price()
{
    return ticket_price;
}

PreferencialPassenger::PreferencialPassenger(pair<string, string> _name, int _age, string _pref_type, string _range, double _ticket_price)
    : Passenger(_name, _age)
{
    prefrencion_type = _pref_type;
    range_of_access = _range;
    ticket_price = _ticket_price;
}

void PreferencialPassenger::get_info() const
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
    cout << endl;
}
double PreferencialPassenger::get_ticket_price()
{
    return ticket_price;
}

MembershipPassenger::MembershipPassenger(pair<string, string> _name, int _age, double _price, string _type) : Passenger(_name, _age)
{
    price = _price;
    type = _type;
}
void MembershipPassenger::get_info() const
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
    cout << endl;
}
double MembershipPassenger::get_ticket_price()
{
    return 0;
}

FareDodgerPassenger::FareDodgerPassenger(pair<string, string> _name, int _age, bool _is_wasted) : Passenger(_name, _age)
{
    is_wasted = _is_wasted;
}
void FareDodgerPassenger::get_info() const
{
    for (int i = 0; i < 15; i++)
        cout << "-";
    cout << endl
         << "Fare Dodger Passenger" << endl;
    cout << name.first << ' ' << name.second << ' ' << age << endl;

    cout << "Is Wasted: " << is_wasted << endl;
    for (int i = 0; i < 15; i++)
        cout << "-";
    cout << endl;
}
double FareDodgerPassenger::get_ticket_price()
{
    return 0;
}

Passenger *PassengerList::operator[](size_t index)
{
    if (index >= size)
        throw out_of_range("Out of range of passengers");
    else if (index >= back)
        throw "Passsenger does not exist";
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
    for (size_t i = 0; i < back; i++)
    {
        delete list[i];
    }
    delete[] list;
}

void PassengerList::pushback(Passenger *p)
{
    if (back == size)
    {
        throw "Has no free slot!";
    }
    else
    {
        list[back] = p;
        back++;
    }
}

void PassengerList::emplace(int index, Passenger *p)
{
    if (back == size)
    {
        throw "Has no free slot!";
    }
    if (index < 0 || index > back)
    {
        throw out_of_range("Index out of range");
    }
    for (int i = back; i > index; i--)
    {
        list[i] = list[i - 1];
    }
    list[index] = p;
    back++;
}

void PassengerList::erase(int index)
{
    if (list[index] == nullptr)
    {
        throw "Passenger does not exist";
    }
    else
    {
        for (int i = index; i < back; i++)
        {
            list[i] = list[i + 1];
        }
        back--;
    }
}

void PassengerList::get_info()
{
    for (int i = 0; i < back; i++)
    {
        /*         if (list[i] == nullptr)
                    break; */
        list[i]->get_info();
    }
}

int PassengerList::get_back()
{
    return back;
}