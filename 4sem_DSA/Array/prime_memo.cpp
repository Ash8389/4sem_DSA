#include <iostream>
using namespace std;

int solve(int n)
{
    int arr[n + 1];
    int count = 0;

    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = true;
    }
    arr[0] = arr[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == true)
        {
            count++;
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    return count;
}
int main()
{
    cout << solve(1000);

    return 0;
}