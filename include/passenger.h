#pragma once

#include <string>
#include <vector>

using namespace std;

// Родительский абстрактный класс Пассажир
class Passenger
{
protected:
    pair<string, string> name;
    int age;

public:
    virtual void getInfo() const = 0;
    Passenger(pair<string, string> _name, int _age);
    virtual ~Passenger();
};

// Пассажир купивший билет
class TicketPassenger : public Passenger
{
    double ticket_price;
    string date;

public:
    void getInfo() const override;
    TicketPassenger(pair<string, string> _name, int _age, string _date, double _ticket_price);
};

// Пассажир с льготами
class PreferencialPassenger : public Passenger
{
    string range_of_access;
    string prefrencion_type;

public:
    void getInfo() const override;
    PreferencialPassenger(pair<string, string> _name, int _age, string _pref_type, string _range);
};

// Пассажир c проездным
class MembershipPassenger : public Passenger
{
    string price;
    string type;

public:
    void getInfo() const override;
    MembershipPassenger(pair<string, string> _name, int _age, string _price, string _type);
};

// Пассажир без билета (заяц)
class FareDodgerPassenger : public Passenger
{
    bool is_wasted;

public:
    void getInfo() const override;
    FareDodgerPassenger(pair<string, string> _name, int _age, bool _is_wasted);
};

// Класс хранящий указатели на объекты типа Passenger
class PassengerList
{
    Passenger **list;
    size_t size;      // size of list
    int freeslot = 0; // last passenger at list

public:
    PassengerList(size_t size);
    ~PassengerList();

    Passenger *operator[](size_t index); // override operator[]

    size_t get_size()
    {
        return size;
    }

    void pushback(Passenger *p);
    void erase(int index);
};