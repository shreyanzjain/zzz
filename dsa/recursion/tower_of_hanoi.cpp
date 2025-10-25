// tower of hanoi problem - aditya verma

#include <iostream>
#include <vector>
#include <stack>

class Solution {
    private:
    public:
        /**
         * @brief 
         * 
         * @param n no. of disks
         * @param s source tower repr
         * @param d destination tower repr
         * @param h helper tower repr
         */
        void solve_hanoi(int n, int s, int d, int h) {
            if(n == 1) {
                std::cout<<"Moving disk " <<n<<" from tower "<<s<<", to tower "<<d<< std::endl;
                return;
            }

            solve_hanoi(n - 1, s, h, d);
            std::cout<<"Moving disk " <<n<<" from tower "<<s<<", to tower "<<d<< std::endl;
            
            solve_hanoi(n - 1, h, d, s);
            return;
        }
};

int main() {
    Solution sol;
    int n;

    std::cout<<"Enter number of disks: ";
    std::cin>>n;

    sol.solve_hanoi(n, 1, 3, 2);
}