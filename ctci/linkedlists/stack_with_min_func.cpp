#include <iostream>
using namespace std;


//stack that stores minimum values at each level of the stack
/*      val  min
 top -> 3 -- 3
        4 -- 4
        5 -- 4
        4 -- 4
*/

class MyStack{
    public:
    int top = -1;
    int size = 0;
    int n;
    int* arr;
    int* min_arr;
    
    MyStack(int n)  {
        this->n = n;
        arr = new int[n];
        min_arr = new int[n];
    }
    
    void push(int val) {
        if(isFull())    {
            cout << "Stack full!" << endl;
        }   else    {
            top++;
            arr[top] = val;
            cout << "Pushed: "<< arr[top]<< endl;
            //if we are at the second element or greater
            if(top > 0) {
                // if the current val to be pushed is < than the previous val
                if(val < min_arr[top - 1])  {
                    min_arr[top] = val;
                }   else    {
                    min_arr[top] = min_arr[top - 1];
                }
            }   else    {
                //if we are at the first element in the stack
                min_arr[top] = val;
            }
        }
    }
    
    void pop(){
        if(isEmpty())   {
            cout << "Stack is Empty!" << endl;
        }   else    {
            cout << "Popped: " << arr[top]<<endl;
            top--;
        }
    }
    
    void stackMin()  {
        if(isEmpty())   {
            cout << "Stack is Empty!" << endl;
        }   else    {
            cout << "Minimum element: " << min_arr[top] << endl; 
        }
    }
    
    bool isEmpty()  {
        if(top == - 1)    {
            return true;
        }   else    {
            return false;
        }
    }
    
    bool isFull()   {
        if(top == n - 1){
            return true;
        }   else    {
            return false;
        }
    }
};

int main()  {
    MyStack mystack(5);
    mystack.push(5);
    mystack.push(3);
    mystack.push(5);
    mystack.push(2);
    mystack.push(5);
    
    mystack.stackMin();
    mystack.pop();
    
    mystack.stackMin();
    mystack.pop();
    
    mystack.stackMin();
    mystack.pop();
    
    mystack.stackMin();
    mystack.pop();
    
    mystack.stackMin();
    mystack.pop();
    
    mystack.stackMin();
    mystack.pop();
    return 0;
}