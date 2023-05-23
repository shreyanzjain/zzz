#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data)  {
        this -> data = data;
    }
};

void addNode(Node* &n, int data){
    Node* temp = n;
    n = new Node(data);
    temp -> next = n;
}

int main()  {
    //creating the LL
    Node* n = new Node(10);
    Node* head = n;
    Node* temp = n;
    
    addNode(n, 20);
    addNode(n, 30);
    addNode(n, 40);
    addNode(n, 50);
      
    // {10, 20, 30, 40, 50}: delete the 4th Node i.e 40
    temp = head;
    while(temp -> data != 40)   {
        temp = temp -> next;
    }
    
    // just swap values for 4th and 5th, and then delete the 5th node
    cout << temp -> data;
    n = temp -> next;
    temp -> data = n -> data;
    delete n;
    
    cout << "\t" << temp -> data;
    
    return 0;
}