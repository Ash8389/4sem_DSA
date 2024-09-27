#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int i = start;
    int j = end;
    int pivot = arr[start];

    while (i < j)
    {
        while (arr[i] <= pivot && i < end)
        {
            i++;
        }
        while (arr[j] >= pivot && j > start)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);
    return j;
}
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int part = partition(arr, start, end);
        quickSort(arr, start, part - 1);
        quickSort(arr, part + 1, end);
    }
}
int main()
{

    int arr[] = {5, 7, 6, 3, 10, 8, 4, 8, 15, 65, 25, 14};
    int size = (sizeof(arr) / sizeof(int));
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}