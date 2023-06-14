/*
Using selection sort, constant extra space
*/

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int val)
    {
        this->data = val;
    }
};

int main()
{
    vector<int> arr;
    int size;

    Node *head = NULL;
    Node *n = new Node(0);
    Node *temp = n;

    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            n->data = arr[i];
            delete head;
            head = n;
        }
        else
        {
            temp = new Node(arr[i]);
            n->next = temp;
            n = temp;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        Node *min = temp;
        Node *tmp2 = temp->next;
        while (tmp2 != NULL)
        {
            if (tmp2->data < min->data)
            {
                min = tmp2;
            }
            tmp2 = tmp2->next;
        }
        int tmp = min->data;
        min->data = temp->data;
        temp->data = tmp;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    } cout << endl;

    temp = head;
    Node* prev = temp;
    temp = temp->next;

    while(temp != NULL && prev->next != NULL)   {
        if(prev->data == temp->data)  {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }   else{
            prev = temp;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    return 0;
}