/* Sliding Window: O(N2) */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        map<char,int> char_counts;
        string ans = "";
        string temp = "";

        while(right < s.size()){
            if(char_counts.find(s[right]) == char_counts.end()){
                char_counts[s[right]]++;
                temp += s[right];
                if(temp.size() > ans.size()){
                    ans = temp;
                }
            }   else    {
                char_counts.clear();
                left++;
                char_counts[s[left]]++;
                temp = s[left];
                right = left;
            }
            right++;
        };

        return ans.size();
    }
};