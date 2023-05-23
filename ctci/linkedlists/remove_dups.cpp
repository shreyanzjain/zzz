#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()  {
    unordered_map<int, int> value_counts;
    list<int> nums = {2,3,5,2,9,9};
    list<int> :: iterator itr;
    
    
    for(itr = nums.begin(); itr != nums.end(); itr++)   {
        value_counts[*itr]++;
        if(value_counts[*itr] > 1)  {
            itr = --nums.erase(itr);
            //when we erase an element the iterator  umust be assigned again, 
            //as the iterator that held the erased value got deleted. 
            //So, we must update the iterator to the next element, 
            //that is when we erased 2 here, our iterator went to 9, 
            //and since the for loop increments the iterator 
            //we must decrement it so both operations get cancelled out!
        }
    }
    
    for(itr = nums.begin(); itr != nums.end(); itr++)   {
        cout << *itr << "\t";
    }
}