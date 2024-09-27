#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    return x * myPow(x, n - 1);
}
int main()
{
    cout << (double)myPow(2, 10);

    return 0;
}