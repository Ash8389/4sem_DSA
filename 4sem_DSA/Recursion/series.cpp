#include <iostream>
using namespace std;

//!-> 1 - 1/2 + 1/3 - ... + 1/n

// float solve(int n)
// {
//     static float even;
//     static float odd;
//     if (n == 0)
//     {
//         return odd - even;
//     }
//     else if (n % 2 == 0)
//     {
//         even += (1.0 / n);
//         return solve(n - 1);
//     }
//     else
//     {
//         odd += (1.0 / n);
//         return solve(n - 1);
//     }
// }

float solve(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return -(1.0 / n) + solve(n - 1);
    }
    else
    {
        return (1.0 / n) + solve(n - 1);
    }
}
int main()
{

    cout << solve(3);

    return 0;
}