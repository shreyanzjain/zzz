// https://codeforces.com/problemset/problem/59/A

#include <iostream>
#include <string>

using namespace std;

int count_case_chars(string& s, int& upper_cnt, int& lower_cnt){
    for(int i = 0; i < s.size(); i++){
        if((int)s[i] < 97 && (int)s[i] >= 65){
            upper_cnt++;
        }   else{
            lower_cnt++;
        }
    }
    return 0;
}

int main(){
    string s;
    cin >> s;

    int upper_cnt = 0, lower_cnt = 0;
    count_case_chars(s, upper_cnt, lower_cnt);

    if(upper_cnt > lower_cnt){
        for(int i = 0; i < s.size(); i++){
            s[i] = toupper(s[i]);
        }
    }   else{
        for(int i = 0; i < s.size(); i++){
            s[i] = tolower(s[i]);
        }
    }

    cout << s;
    return 0;
}