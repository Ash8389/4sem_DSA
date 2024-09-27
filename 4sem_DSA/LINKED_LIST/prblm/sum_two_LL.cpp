#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void build(Node *&head)
{
    int data;

    if (head == NULL)
    {
        cout << "Enter head data: ";
        cin >> data;

        if (data == -1)
            return;

        head = new Node(data);
    }

    Node *temp = head;

    while (1)
    {
        cout << "Enter next node data: ";
        cin >> data;

        if (data == -1)
            break;

        temp->next = new Node(data);
        temp = temp->next;
    }
}

void print(Node *head)
{
    cout << endl;
    if (head == NULL)
        cout << "Linked List is empty";
    else
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
}

Node *reverse(Node *head)
{
    Node *next = head->next;
    Node *curr = head;
    Node *prev = NULL;

    while (curr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next)
            next = next->next;
    }

    return prev;
}

Node *sum(Node *h1, Node *h2)
{
    if (h1 == NULL && h2 == NULL)
        return NULL;

    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    h1 = reverse(h1);
    h2 = reverse(h2);
    // cout << "YES" << endl;
    int sum = 0;
    int carry = 0;

    Node *dummyNode = new Node(0);
    Node *temp = dummyNode;

    // cout << "YES2" << endl;
    while (h1 != NULL && h2 != NULL)
    {
        sum = h1->data + h2->data;

        h1 = h1->next;
        h2 = h2->next;

        sum += carry;

        carry = sum / 10;

        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
        // cout << "YES3" << endl;
    }
    while (h1 != NULL)
    {
        sum = h1->data;
        h1 = h1->next;

        sum += carry;

        carry = sum / 10;

        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }
    while (h2 != NULL)
    {
        sum = h2->data;
        h2 = h2->next;

        sum += carry;

        carry = sum / 10;

        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }

    if (carry > 0)
    {
        Node *newNode = new Node(carry);
        temp->next = newNode;
        temp = temp->next;
    }
    dummyNode = reverse(dummyNode->next);
    // cout << "DONE" << endl;
    return dummyNode;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    build(head1);
    // print(head1);
    build(head2);
    // print(head2);
    Node *ans = sum(head1, head2);
    print(ans);

    return 0;
}