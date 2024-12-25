#include <iostream>
#include <math.h>

using namespace std;

double getSqrt(double n)
{
    if (n >= 0)
    {
        return sqrt(n);
    }
    throw string{"Cant extract the square root from a negative number " + to_string(n)};
}

void test(double n)
{
    try
    {
        cout << getSqrt(n) << endl;
    }
    catch (string &error_message)
    {
        cout << error_message;
    }
}

int main()
{

    test(1);
    test(-1);

    return 0;
}