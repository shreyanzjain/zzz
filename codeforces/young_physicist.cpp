// https://codeforces.com/problemset/problem/69/A
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int sum_x = 0;
    int sum_y = 0;
    int sum_z = 0;

    int vector_counts;
    cin >> vector_counts;

    for(int i = 0; i < vector_counts; i++){
        int x, y, z;
        cin >> x;
        cin >> y;
        cin >> z;

        sum_x+=x;
        sum_y+=y;
        sum_z+=z;
    }

    if(sum_x == 0 && sum_y == 0 && sum_z == 0){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}