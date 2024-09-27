#include <iostream>
using namespace std;

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

void insert(node *&head, int data, int pos)
{
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        head->next = head;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        node *newNode = new node(data);
        curr->next = newNode;
        newNode->next = head;
    }
}
void display(node *head)
{
    node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}
int main()
{
    node *head = NULL;
    insert(head, 1, 1);
    insert(head, 2, 1);
    insert(head, 3, 1);

    display(head);

    return 0;
}