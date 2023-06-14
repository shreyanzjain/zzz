#include <iostream>
using namespace std;

struct node {
    int data;
    node* next = NULL;
};

void insertNode(node* &head, node* &n)    {
    int data;
    
    if(head == NULL)    {
        cout<<"Enter a number: ";
        cin>>data;
        n->data = data;
        cout<<"Data inserted!";
        head = n;
    }   else    {
        node* temp = new node;
        cout<<"NOT NULL: Enter a number: ";
        cin>>data;
        n->next = temp;
        temp->data=data;
        n = temp;
    }
}

void deleteNode(node* &head)    {
    int data;
    int ctr = 0;
    int flag = 0;
    if(head==NULL)  {
        cout<<"Empty List!";
    }   else    {
        node* temp = head;
        cout << "Enter a number: ";
        cin >> data;
        while(temp != NULL) {
            if(temp->data == data)  {
                flag = 1;
                break;
            }   else    {
                temp = temp -> next;
                ctr++;
            }
        }
        temp = head;
        if(flag == 1)   {
            for(int i = 0; i < ctr - 1; i++)    {
                temp = temp->next;
            }
            node* prev = temp;
            temp = temp->next;
            prev->next = temp->next;
            delete temp;
        }   else    {
            cout<<"Element not in the list!\n";
        }
    }
}

void displayList(node* &head)  {
    if(head==NULL)  {
        cout<<"Empty List!";
    }
    node* temp = head;
    while(temp!=NULL)   {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

int main()  {
    node* n = new node;
    node* head = NULL;
    
    cout<<n<<endl;
    cout<<n->data<<endl;
    
    int chc = -1;
    while(chc!=4)   {
        cout<<"===================================="<<endl;
        cout << "1. Insert a node\n2. Delete a node\n3. Display the list\n4. Exit\nPlease Select: ";
        cin>>chc;
        
        switch (chc){
            case 1: cout<<"Insert Operation\n";
                    insertNode(head, n);
                    cout<<head->data<<"\t"<<n->data<<endl;
                    break;
            case 2: cout<<"Delete Operation\n";
                    deleteNode(head);
                    break;
            case 3: cout<<"Display Operation\n";
                    displayList(head);
                    break;
            case 4: cout<<"Bye\n";
                    break;
            default: cout<<"Invalid Choice. Please enter a number from (1-4)\n";
                    break;
        }
    }
    while(head != NULL) {
        n = head -> next;
        delete head;
        head = n;
    }
}
