#include <iostream>
#include <cstring>
using namespace std;
int mem[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
// memset(mem, -1, sizeof(mem));
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        mem[n] = n;
        return mem[n];
    }
    else
    {
        if (mem[n - 1] == -1)
        {
            mem[n - 1] = fib(n - 1);
            cout << "(n-1)->" << n - 1 << "->" << mem[n - 1] << endl;
        }
        if (mem[n - 2] == -1)
        {
            mem[n - 2] = fib(n - 2);
            cout << "(n-2)->" << n - 2 << "->" << mem[n - 2] << endl;
        }
        mem[n] = mem[n - 1] + mem[n - 2];
        return mem[n];
    }
}
int main()
{
    cout << fib(5);

    return 0;
}