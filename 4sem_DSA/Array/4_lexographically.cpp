#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[10][10];
    int n;
    char temp[10];

    cout << "enter the size of string: ";
    cin >> n;

    cout << "Enter strings: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    cout << "Printed Lexographically:\n";
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }

    return 0;
}