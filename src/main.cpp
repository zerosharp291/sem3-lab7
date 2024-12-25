#include <iostream>
#include <math.h>

using namespace std;

class SqrtExeption
{

    double number;

public:
    SqrtExeption(double _number) : number(_number) {}

    string getMsg() const
    {
        return "Cant extract the square root from a negative number " + to_string(number);
    }
};

double getSqrt(double n)
{
    if (n >= 0)
    {
        return sqrt(n);
    }
    throw SqrtExeption(n);
}

void test(double n)
{
    try
    {
        cout << getSqrt(n) << endl;
    }
    catch (const SqrtExeption &ex)
    {
        cout << ex.getMsg();
    }
}

int main()
{

    test(1);
    test(-1);

    return 0;
}