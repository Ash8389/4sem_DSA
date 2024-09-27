#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *pre;
    node *next;
    node(int data)
    {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
};

//->INSERT AT HEAD
void insertHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head->pre = temp;
    head = temp;
}

//->INSERT AT TAIL
void insertTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    temp->pre = tail;
    tail = temp;
}

//->INSERT AT POSITION
void insertPosition(node *&head, int pos, int data)
{
    if (pos == 1)
    {
        insertHead(head, data);
        return;
    }
    int cnt = 1;
    node *temp = head;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // cout << "TEMP->data: " << temp->data << endl;
    if (temp->next == NULL)
    {
        // cout << "yes" << endl;
        insertTail(temp, data);
        return;
    }
    node *insert = new node(data);
    // cout << "Insert DATA: " << insert->data << endl;
    insert->pre = temp;
    insert->next = temp->next;
    temp->next->pre = insert;
    temp->next = insert;
}

//->DELETE
void remove(node *&head, int pos)
{
    int cnt = 1;
    if (pos == 1)
    {
        node *temp = head->next;
        head->next = NULL;
        temp->pre = NULL;
        head = temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        while (cnt != pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            curr->next->pre = prev;
            prev->next = curr->next;
        }
        curr->pre = NULL;
        curr->next = NULL;
    }
}

//->DISPLAY
void display(node *head)
{
    while (head)
    {
        cout << "( " << head->pre << ", " << head->data << ", " << head->next << ")"
             << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = new node(3);
    node *tail = head;
    insertHead(head, 2);
    insertHead(head, 1);

    // display(head);

    insertTail(tail, 5);
    insertTail(tail, 6);

    insertPosition(head, 4, 4);
    display(head);
    remove(head, 5);
    display(head);

    return 0;
}