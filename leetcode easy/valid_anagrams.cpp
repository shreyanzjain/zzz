class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> s_map;
        unordered_map <char, int> t_map;

        if(s.length() != t.length())    {
            return false;
        }
        
        for(int i = 0; i < s.length(); i++) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        unordered_map <char, int> :: iterator s_itr;
        for(s_itr = s_map.begin(); s_itr != s_map.end(); s_itr++){
            if(t_map[s_itr->first] != s_itr->second)    {
                return false;
            }
        }
        return true;
    }
};