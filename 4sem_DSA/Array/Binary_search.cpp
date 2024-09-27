#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1, 14, 15, 16, 19, 24};

    int r, l, mid, key = 14;

    l = 0;
    r = 6 - 1;

    while (l <= r)
    {

        mid = l + ((r - l) / 2);

        if (key == arr[mid])
        {
            cout << "Element is at index: " << mid << endl;
            break;
        }
        else if (key < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return 0;
}