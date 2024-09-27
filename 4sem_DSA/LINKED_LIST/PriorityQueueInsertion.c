void insertQueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    struct Node *current = head;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (current->next != NULL && current->next->data < value)
        {
            current = current->next;
        }
        if (current == head)
        {
            if (current->data > value)
            {
                newNode->next = current;
                head = newNode;
            }
            else
            {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
        else
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}