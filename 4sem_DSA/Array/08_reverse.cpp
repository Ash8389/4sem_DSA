#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateLeft(vector<int> &arr, int k)
{
    int n = arr.size();
    // Adjust k to handle cases where k > n
    k = k % n;

    // Reverse the entire array
    reverse(arr, 0, n - 1);
    // Reverse the first k elements
    reverse(arr, 0, k - 1);
    // Reverse the remaining elements
    reverse(arr, k, n - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    rotateLeft(arr, k);

    cout << "Array after rotating left by " << k << " times: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
