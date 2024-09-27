#include <iostream>
using namespace std;

// int sum(int *p, int size)
// {
//     int s = 0;
//     for (int i = 0; i < size; i++)
//     {
//         s += *(p + i);
//     }
//     return s;
// }

int search(int *p, int size, int key)
{
    int f = 0;
    int pos;
    for (int i = 0; i < 5; i++)
    {
        if (*(p + i) == key)
        {
            f = 1;
            pos = i;
            cout << key << " is found at Index: " << pos << endl;
        }
    }
    if (f == 0)
    {
        cout << "Element not found";
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 5, 5}, n;
    cout << "Enter elements for search: ";
    cin >> n;

    search(arr, 5, n);

    return 0;
}