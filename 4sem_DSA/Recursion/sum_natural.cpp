#include <iostream>
using namespace std;
int fact(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}
int sumNatural(int n)
{
    static int res;
    if (n == 1)
    {
        return n;
    }
    res += fact(n);
    cout << "res->" << res << endl;
    sumNatural(n - 1);
    return 1 + res;
}
int main()
{
    cout << sumNatural(5);

    return 0;
}