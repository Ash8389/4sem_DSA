#include <iostream>
using namespace std;

//->NODE created
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//->INSERT at HEAD
void insertHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

//->INSERT at TAIL
void insertTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

//->INSERT at POSITION
void insertPosition(node *&head, int position, int data)
{
    if (position == 1)
    {
        insertHead(head, data);
        return;
    }
    else
    {
        int cnt = 1;
        node *temp = head;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next == NULL)
        {
            insertTail(temp, data);
            return;
        }
        node *insert = new node(data);
        insert->next = temp->next;
        temp->next = insert;
    }
}

//->DELETE NODE
void remove(node *&head, int pos)
{
    node *curr = head;
    if (pos == 1)
    {
        curr = curr->next;
        head->next = NULL;
        head = curr;
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1)
    {
        curr = curr->next;
        cnt++;
    }
    node *temp = curr->next;
    if (temp->next == NULL)
    {
        curr->next = NULL;
    }
    else
    {
        curr->next = temp->next;
        temp->next = NULL;
    }
}

//->REVERSE NODE USING RECURSION
node *reverse(node *&head, node *pre = NULL)
{
    if (head->next == NULL)
    {
        head->next = pre;
        return head;
    }

    node *next = head->next;
    head->next = pre;
    pre = head;
    reverse(next, pre);
}

//->DISPLAY Linked List
void display(node *head)
{
    while (head)
    {
        cout << "( " << head->next << " , " << head->data << " )"
             << ", ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = new node(3);
    cout << sizeof(head) << endl;
    node *tail = head;

    insertHead(head, 2);

    insertPosition(head, 1, 1);

    insertTail(tail, 5);

    insertPosition(head, 5, 6);

    insertPosition(head, 4, 4);

    display(head);
    remove(head, 3);

    cout << "BEFORE REVERSE" << endl;
    display(head);

    node *rev = reverse(head);

    cout << "AFTER REVERSE" << endl;
    display(rev);

    return 0;
}