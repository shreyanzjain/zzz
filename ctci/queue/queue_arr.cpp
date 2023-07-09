#include <iostream>

using namespace std;

struct queue    {
    int arr[100] = {0};

    int MAX_ELEMENTS = 100;
    int front = 0;
    int rear = 0;
};

void enQueue(queue& que, int val){
    if(que.rear == que.MAX_ELEMENTS - 1){
        cout << "Queue is FULL!!!"<<endl;
        return ;
    }   else{
        que.arr[que.rear] = val;
        que.rear++;
    }
}

void deQueue(queue& que){
    if(que.front > que.rear){
        cout<<"Queue is EMPTY!!!"<<endl;
        return ;
    }   else{
        cout << que.arr[que.front] << " removed."<<endl;
        que.front++;
    }
    return;
}

void displayQueue(queue& que){
    if(que.front > que.rear){
        cout<<"Queue is EMPTY!!!"<<endl;
        return ;
    }   else if(que.front == que.rear){
        cout << que.arr[que.front] << endl;
    }   else{
        int tmp_front = que.front;
        int tmp_rear = que.rear;

        while(tmp_front < tmp_rear){
            cout << que.arr[tmp_front] << " ";
            tmp_front++;
        }
    }
}

int main(){
    queue que;
    int chc = -1;
    cout << "Queue initialising....\nMax elements in queue: (1 - 100): ";
    cin >> que.MAX_ELEMENTS;

    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";

    while(chc != 4){

        cout << "Enter your choice: ";
        cin >> chc;

        if(chc == 1){
            int val;
            cout<<"Enter the value to append: ";
            cin >> val;
            enQueue(que, val);
        }   else if(chc == 2){
            deQueue(que);
        }   else if(chc == 3){
            displayQueue(que);
        }   else if(chc == 4){
            break;
        }   else{
            cout << "Invalid choice!" <<endl;
        }
    }
    return 0;
}