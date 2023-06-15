/*
Create a reverse linked list and then compare the first halves
of the original and the revesered list
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data = 0;
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

Node *createRev(Node *&head, int size)
{
    Node *n = head;
    Node *t = new Node;
    if (n != NULL)
    {
        t->data = n->data;
        n = n->next;
    }   else{
        cout << "Empty list.";
        return n;
    }
    while (n != NULL)
    {
        Node* tmp_n = new Node;
        tmp_n->data = n->data;
        tmp_n->next = t;
        t = tmp_n;
        n = n->next;
    }
    return t;
}

int main()
{
    Node *head = NULL;
    head = createList(head);
    int size = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    Node *n = createRev(head, size);
    Node* rev_tmp = n;
    temp = head;

    for(int i = 0; i < size/2; i++){
        if(rev_tmp->data == temp->data){
            rev_tmp = rev_tmp->next;
            temp = temp->next;
        }   else    {
            cout << "Is not palindrome."<<endl;
            return 0;
        }
    }
    
    cout << "Is palindrome."<<endl;
    return 0;
}