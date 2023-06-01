#include <iostream>
#include <stack>
using namespace std;

// func that displays a stack
void display_stack(stack<int> st)   {
    if(!st.empty()) {
        while(!st.empty())  {
            cout << st.top() << endl;
            st.pop();
        }
    }   else    {
        cout << "Empty stack." << endl;
    }
}

int main()  {
    stack<int> st;
    stack<int> temp;
    int size;

    // taking input
    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter the elements:"<< endl;    
    for(int i = 0; i < size; i++)   {
        int val;
        cin >> val;
        st.push(val);
    }

    // display original and temporary stacks
    cout << "= = = = = ="<<endl;
    display_stack(st);
    cout << "= = = = = ="<<endl;
    display_stack(temp);
    cout << "= = = = = ="<<endl;

    temp.push(st.top());
    st.pop();

    /*as long as the original stack is not emptied,
    we keep adding elements to the temp stack, while
    checking at each entry if the element to be added
    is greater than the element at the top of the temp stack
    if it is, then we pop it and push it to the "original stack's" top,
    and loop till we find a element in the temp
    stack that is greater than the element we are adding
    once found, or we hit the bottom of the temp stack, we push the
    element onto the temp stack.*/

    while(!st.empty())  {
        if(st.top() <= temp.top())   {
            temp.push(st.top());
            st.pop();
        }   else    {
            int x = st.top();
            st.pop();
            while(!temp.empty() && x > temp.top())   {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(x);
        }
    }

    cout << "Sorted stack: (top = min; bot = max)" << endl;
    display_stack(temp);
    cout << "= = = = = ="<<endl;
    return 0;
}