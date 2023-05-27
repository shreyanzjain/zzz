#include <iostream>

using namespace std;

class Heap{
    public:
    int arr[100];
    int size;
    
    Heap()  {
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val)    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        
        while(index > 1)    {
            int parent = index / 2;
            if(arr[index] > arr[parent])    {
                swap(arr[index], arr[parent]);
                index = parent;
            }   else    {
                return ;
            }
        }
    }
};

int main()  {
    Heap obj;
    obj.insert(33);
    obj.insert(44);
    obj.insert(30);
    obj.insert(50);
    
    for(int i = 1; i <= obj.size; i++)   {
        cout << obj.arr[i] << "\t";
    }
    return 0;
}