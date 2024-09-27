#include <iostream>
using namespace std;

// int main()
// {
//     int s = 0, n = 12345;
//     do
//     {
//         s = 0;
//         while (n > 0)
//         {
//             s = s + (n % 10);
//             n = n / 10;
//         }
//         n = s;
//         cout << n << endl;
//     } while (!(s > 0 && s < 10));

//     return 0;
// }

// int main()
// {
//     int n = 5;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 5;
//     char ch = 'A';

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         char ch = 'A';
//         for (int j = 1; j <= i; j++)
//         {
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 5;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             if ((i + j) % 2 == 0)
//             {
//                 cout << "1 ";
//             }
//             else
//             {
//                 cout << "0 ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 5;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= 2 * i - 1; j++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 4;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int k = n - i; k > 0; k--)
//         {
//             cout << " ";
//         }
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 4;
//     int c;
//     for (int i = 1; i <= n; i++)
//     {
//         c = n;
//         for (int k = n - i; k > 0; k--)
//         {
//             cout << " ";
//         }
//         c = i;
//         for (int j = 1; j <= i; j++)
//         {
//             // cout << i - j + 1;
//             cout << c;
//             c--;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == 1 || j == 1 || i == n || j == n)
//                 cout << "*";
//             else
//                 cout << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main()
// {
//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j || j + i == 6)
//                 cout << "*";
//             else
//             {
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

int main()
{
    int n = 5;
    string r;

    while (n != 0)
    {
        cout << "n-->" << n << endl;
        int temp = n & 1;
        cout << "temp" << temp << endl;
        r = to_string(temp) + r;
        cout << "r-->" << r << endl;
        n = n >> 1;
    }
    cout << r << endl;
    return 0;
}
