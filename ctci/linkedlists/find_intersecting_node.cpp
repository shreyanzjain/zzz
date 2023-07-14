#include <iostream>
#include <unordered_set>

using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;
};

int main(){
    Node f_head;
    f_head.data = 3;
    Node one;
    one.data = 7;
    Node two;
    two.data = 2;

    Node s_head;
    s_head.data = 4;

    f_head.next = &one;     
    one.next = &two;
    s_head.next = &one;

    Node* temp = &f_head;
    while(temp != NULL){
        cout << temp << " ";
        temp = temp->next;
    } cout << endl;

    temp = &s_head;
    while(temp != NULL){
        cout << temp << " ";
        temp = temp->next;
    } cout << endl;

    // f_head -> one -> two
    //            ^
    // s_head ----|

    unordered_set<Node*> address_set;
    temp = &f_head;
    while(temp != NULL){
        address_set.insert(temp);
        temp = temp->next;
    }

    bool flag = 0;
    temp = &s_head;
    while(temp != NULL){
        if(address_set.find(temp) != address_set.end()){
            cout << "The intersecting node: "<<temp<<endl;
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(flag = 0){
        cout << "No nodes intersect!"<<endl;
    }
    return 0;
}