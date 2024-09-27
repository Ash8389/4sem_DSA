#include <iostream>
#include <stack>

using namespace std;

void sortinsert(stack<int> &s, int x)
{
    if (s.empty() || x > s.top())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortinsert(s, x);
    s.push(temp);
}
void sortStack(stack<int> &s)
{
    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        sortStack(s);
        sortinsert(s, x);
    }
}

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(14);
    s.push(-3);
    s.push(10);
    s.push(5);
    s.push(25);
    s.push(3);

    cout << "Before Sorting" << endl;
    display(s);

    sortStack(s);

    cout << "After Sorting" << endl;
    display(s);

    return 0;
}