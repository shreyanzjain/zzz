#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;
};

void enqueue(Node*& front, Node*& back){
    int val;
    cout << "Enter the value: ";
    cin >> val;

    if(front == NULL){        
        Node* n = new Node;
        n->data = val;
        back = n;
        front = n;
    }   else{
        Node* n = new Node;
        n->data = val;

        back->next = n;
        back = back->next;
    }
}

void dequeue(Node*& front){
    if(front == NULL){
        cout << "No value in queue to dequeue!!!"<<endl;
    }   else{
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void display(Node*& front){
    if(front == NULL){
        cout << "Empty Queue!" <<endl;
    }   else{
        Node* temp = front;
        while(temp != NULL){
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    Node* front = NULL;
    Node* back = NULL;

    int opt = -1;
    while(opt != 4){
        cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Exit"<<endl;
        cin >> opt;
        switch(opt){
            case 1: enqueue(front, back);
                    break;
            case 2: dequeue(front);
                    break;
            case 3: display(front);
                    break;
            case 4: cout << "Bye!" << endl;
                    break;
            default: cout << "ERROR: NO SUCH OPTION!!!"<< endl;
        }
    }
    return 0;
}