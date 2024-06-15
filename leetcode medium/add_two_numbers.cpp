#include <iostream>

using namespace std;

struct node{
    int val;
    node* next;
};

node* add_nums(node* &l1, node* &l2){
    node* l1_temp = l1;
    node* l2_temp = l2;
    node* ans;
    node* t = ans;

    int ctr_1 = 0;
    int ctr_2 = 0;

    while(l1_temp != NULL){
        ctr_1++;
        l1_temp = l1_temp->next;
    }

    while(l2_temp != NULL) {
        ctr_2++;
        l2_temp = l2_temp->next;
    }

    l1_temp = l1;
    l2_temp = l2;

    if(ctr_1 >= ctr_2){
        int carry = 0;
        while(l2_temp != NULL){
            t->val = l1_temp -> val + l2_temp->val + carry;
            if(t->val > 9){
                carry = 1;
            }
        }
    }   else{

    }
}

int main(){

    return 0;
}