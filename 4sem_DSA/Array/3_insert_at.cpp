#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 3, 4, 5, 6}, n, num, pos;
    cout << "Enter the size of an array: ";
    cin >> n;
    cout << "Enter the no and position: ";
    cin >> num >> pos;
    n++;
    for (int i = n - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = num;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}