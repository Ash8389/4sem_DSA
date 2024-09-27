#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int left = start;
    int right = mid + 1;
    // vector<int> temp;
    int temp[end - start];
    int cnt = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            // temp.push_back(arr[left]);
            temp[cnt] = arr[left];
            left++;
        }
        else
        {
            // temp.push_back(arr[right]);
            temp[cnt] = arr[right];
            right++;
        }
        cnt++;
    }
    while (left <= mid)
    {
        // temp.push_back(arr[left]);
        temp[cnt] = arr[left];
        cnt++;
        left++;
    }
    while (right <= end)
    {
        // temp.push_back(arr[right]);
        temp[cnt] = arr[right];
        cnt++;
        right++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + (end - start) / 2);
        mergeSort(arr, 0, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {5, 7, 6, 3, 10, 8, 4, 8, 15, 65, 25, 14};
    int size = (sizeof(arr) / sizeof(int));
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}