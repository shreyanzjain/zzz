#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MyStack{
    public:
    int top = -1;
    int size = 0;
    int n;
    int *arr;
    
    MyStack(int n)    {
        this -> n = n;
        arr = new int[this -> n];
    }
    
    void push(int val){
        if(!isFull())   {
            top++;
            arr[top] = val;
            size++;
        }   else    {
            cout << "Stack is full!!\n";
        }
    }
    
    int pop()   {
        if(!isEmpty())  {
            top--;
            size--;
            return arr[top + 1];
        }   else    {
            cout << "Stack is empty!!\n";
            return -1;
        }
    }
    
    int peek()  {
        return arr[top];
    }
    
    void display()  {
        for(int i = size - 1; i >= 0; i--)  {
            cout << arr[i] <<endl;
        }
    }
    
    int isFull()    {
        if(top == this -> n - 1) {
            return true;
        }   else    {
            return false;
        }
    }
    
    int isEmpty()   {
        if(top == -1)   {
            return true;
        }   else    {
            return false;
        }
    }
    
};

int main()  {
    MyStack mystack(5);
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    //now that the stack is filled let's try to over fill
    mystack.push(1);
    mystack.push(2);
    
    mystack.display();
    
    cout << "Top: "<< mystack.top << endl;
    cout << "Top element: " << mystack.peek() << endl;
    cout << "Size:" << mystack.size<< endl;
    
    cout << "Popping: "<< mystack.pop() << endl;
    cout << "Top: "<< mystack.top << endl;
    cout << "Top element: " << mystack.peek() << endl;
    cout << "Size:" << mystack.size<< endl;
    
    cout << "Popping: "<< mystack.pop() << endl;
    cout << "Popping: "<< mystack.pop() << endl;
    cout << "Popping: "<< mystack.pop() << endl;
    cout << "Popping: "<< mystack.pop() << endl;
    
    //now that stack is empty lets try to delete more elements
    cout << "Popping: "<< mystack.pop() << endl;
    
    return 0;
}