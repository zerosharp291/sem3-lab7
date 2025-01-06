#include <iostream>
#include <math.h>

using namespace std;

class SqrtException : public std::exception
{

private:
    double number;       // Хранит число, для которого произошла ошибка
    std::string message; // Сообщение об ошибке

public:
    SqrtException(double _number) : number(_number)
    {
        message = "Can't extract the square root from a negative number: " + std::to_string(number);
    }

    // Переопределяем метод what() для возврата сообщения об ошибке
    virtual const char *what() const noexcept override
    {
        return message.c_str();
    }
};

double getSqrt(double n)
{
    if (n >= 0)
    {
        return sqrt(n);
    }
    throw SqrtException(n);
}

void test(double n)
{
    try
    {
        cout << getSqrt(n) << endl;
    }
    catch (const SqrtException &ex)
    {
        cout << ex.what();
    }
}

int main()
{

    test(1);
    test(-1);

    return 0;
}