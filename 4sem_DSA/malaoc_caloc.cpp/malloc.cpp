#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int *ptr = (int *)malloc(5 * sizeof(int));

    cout << ptr << endl;
    if (ptr == NULL)
    {
        cout << "Memory is not allocated" << endl;
    }
    else
    {
        cout << "Memory allocated" << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> ptr[i];
        }
        for (int i = 0; i < 5; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    ptr = (int *)realloc(ptr, 10 * sizeof(int));

    cout << ptr << endl;
    for (int i = 5; i < 10; i++)
    {
        cin >> ptr[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << ptr[i] << " ";
    }

    free(ptr);

    return 0;
}