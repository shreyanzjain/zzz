/* Implementing a animal shelter using queues */
#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        string name;
        Node* next = NULL;
};

void enqueue(Node*& front, Node*& back, string name){
    if(front == NULL){        
        Node* n = new Node;
        n->name = name;
        back = n;
        front = n;
    }   else{
        Node* n = new Node;
        n->name = name;

        back->next = n;
        back = back->next;
    }
}

void dequeue(Node*& front){
    if(front == NULL){
        cout << "None left!"<<endl;
    }   else{
        Node* temp = front;
        front = front->next;
        cout << "You have chosen: " << temp->name << endl;
        delete temp;
    }
}

void display(Node*& front){
    if(front == NULL){
        cout << "None left!" <<endl;
    }   else{
        Node* temp = front;
        while(temp != NULL){
            cout << temp->name<<" ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    Node* dog_front = NULL;
    Node* dog_back = NULL;

    Node* cat_front = NULL;
    Node* cat_back = NULL;

    char animal;
    string name;
    int ctr = 0;
    int chc = -1;

    while(chc!=3){
        cout << "1. Insert Pet\n2. Get Pet\n3. Exit\n";
        cin >> chc;
        switch(chc){
            case 1: cout << "Which pet do you want to add? (c -> Cat or d -> Dog): ";
                    cin >> animal;
                    switch(animal){
                        case 'c': cout << "Name: ";
                                    cin >> name;
                                    enqueue(cat_front, cat_back, name);
                                    ctr++;
                                    break;
                        case 'd': cout << "Name: ";
                                    cin >> name;
                                    enqueue(dog_front, dog_back, name);
                                    ctr++;
                                    break;
                        default: cout << "invalid choice!!" << endl;
                    }
                    break;
            case 2: cout << "Which pet do you want to get? (c -> Cat or d -> Dog or (any character) -> Random): ";
                    cin >> animal;
                    switch(animal){
                        case 'c': dequeue(cat_front);
                                    ctr++;
                                    break;
                        case 'd': dequeue(dog_front);
                                    ctr++;
                                    break;
                        default: if(ctr % 2 == 0){
                                    cout<<"A cat! ";
                                    dequeue(cat_front);
                                    }   else{
                                    cout << "A dog! ";
                                    dequeue(dog_front);
                                    }
                                    ctr++;
                                    break;
                    }
                    break;
            case 3: break;
            default: cout << "Invalid Choice! "<<endl;
                    break;
        }
    }
    return 0;
}