#include <iostream>
using namespace std;

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                s1 += arr[j][i];
                s4 += arr[i][j];
            }
            else if (i == 1)
            {
                s2 += arr[j][i];
                s5 += arr[i][j];
            }
            else if (i == 2)
            {
                s3 += arr[j][i];
                s6 += arr[i][j];
            }
            if (i == j)
            {
                s7 += arr[i][j];
            }
            if ((i + j) == (3 - 1))
            {
                s8 += arr[i][j];
            }
        }
    }
    cout << " col ->: " << s1 << " " << s2 << " " << s3 << " " << endl;
    cout << "row ->: " << s4 << " " << s5 << " " << s6 << endl;
    cout << "Dig-L: " << s7 << " " << endl;
    cout << "Dig-R: " << s8 << " " << endl;

    return 0;
}