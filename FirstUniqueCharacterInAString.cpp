//https://leetcode.com/problems/first-unique-character-in-a-string/description/
//Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//s = "leetcode"
//return 0.
//
//s = "loveleetcode",
//return 2.
//Note: You may assume the string contain only lowercase letters.

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vt(26,0);
        for(auto& a : s)
            vt[a-'a']++;
        
        for(int i=0;i<s.length();i++)
            if(vt[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};