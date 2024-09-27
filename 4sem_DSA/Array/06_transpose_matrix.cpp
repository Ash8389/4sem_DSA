#include <iostream>
using namespace std;

void dis(int arr[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of the square Matrix: ";
    cin >> n;

    int arr[10][10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "\nOriginal matrix is: \n";
    dis(arr, n);

    //. for (int i = 0; i < n; i++)
    //. {
    //.     for (int j = 0; j < n; j++)
    //.     {
    //.         if ((i + j) > (i + i))
    //.         {
    //.             swap(arr[i][j], arr[j][i]);
    //.         }
    //.     }
    //. }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    cout << "\nTranspose of given matrix is: \n";

    dis(arr, n);

    return 0;
}