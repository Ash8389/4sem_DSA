#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return n * fact(n - 1);
}
int solve(int n)
{
    static int res;
    if (n == 0)
    {
        return res;
    }
    res += fact(n);
    solve(n - 1);
}
int main()
{

    cout << solve(5);
    return 0;
}