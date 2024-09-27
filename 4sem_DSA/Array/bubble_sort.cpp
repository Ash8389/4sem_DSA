#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int f = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                f = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (f == 0)
            break;
    }
}
int main()
{
    int arr[8] = {33, 22, 55, 44, 77, 88, 55, 12};

    cout << "BEFORE" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "AFTER" << endl;

    sort(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}