#include <iostream>
#include <queue>
using namespace std;
void display(queue<int>);

void sortinsert(queue<int> &q, int x)
{
    if (q.empty() || x > q.front())
    {
        display(q);
        q.push(x);
        return;
    }
    display(q);
    int temp = q.front();
    q.pop();
    sortinsert(q, x);
    q.push(temp);
}
void sortQueue(queue<int> &q)
{
    if (!q.empty())
    {
        int x = q.front();
        q.pop();
        display(q);
        sortQueue(q);
        sortinsert(q, x);
    }
}

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> que;

    que.push(10);
    que.push(6);
    que.push(5);
    que.push(4);
    que.push(-5);
    que.push(1);
    que.push(25);
    que.push(15);

    cout << "Before Sorting" << endl;
    display(que);

    sortQueue(que);

    cout << "After Sorting" << endl;
    display(que);
    return 0;
}