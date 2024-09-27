#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    int mid = start + end / 2;
    if (start > end)
    {
        return -1;
    }
    else if (arr[mid] == key)
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        return binarySearch(arr, start, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, end, key);
    }
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    cout << binarySearch(arr, 0, size, 4);

    return 0;
}