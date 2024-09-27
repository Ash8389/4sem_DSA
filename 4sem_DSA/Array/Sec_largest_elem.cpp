#include <iostream>
#include <limits.h>
using namespace std;

void solve(int a[], int n)
{
    int max = a[0];
    int secMax = INT_MIN;
    int min = a[0];
    int secMin = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            secMax = max;
            max = a[i];
        }
        else if (a[i] < max && a[i] > secMax)
        {
            secMax = a[i];
        }
        if (a[i] < min)
        {
            secMin = min;
            min = a[i];
        }
        else if (a[i] > min && a[i] < secMin)
        {
            secMin = a[i];
        }
    }
    cout << "MAX = " << max << endl;
    cout << "SEC_MAX = " << secMax << endl;
    cout << "MAX = " << min << endl;
    cout << "SEC_MAX = " << secMin << endl;
}
int main()
{
    int arr[] = {4, 3, 85, 80, 5, 7, 6, 10, 15, 65, 25, 14};
    int size = (sizeof(arr) / sizeof(int));
    solve(arr, size);

    return 0;
}