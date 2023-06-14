/* partition.cpp but with a developer defined linked list */

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

Node *createList(Node *&head)
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    Node *n = new Node;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        if (head == NULL)
        {
            n->data = val;
            head = n;
        }
        else
        {
            Node *temp = new Node;
            temp->data = val;
            n->next = temp;
            n = temp;
        }
    }

    return head;
}

int main()
{
    Node *head = NULL;
    head = createList(head);

    int x;
    cout << "Enter the partition (x): ";
    cin >> x;

    Node *left = head;
    Node *right = left->next;

    while (right != NULL)
    {
        if (left->data >= x)
        {
            swap(left->data, right->data);
            right = right->next;
        }
        else
        {
            left = left->next;
            if (right->next != NULL)
            {
                right = right->next;
            }
        }
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}