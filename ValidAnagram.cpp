//https://leetcode.com/problems/valid-anagram/description/
//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//
//Note:
//You may assume the string contains only lowercase alphabets.
//
//Follow up:
//What if the inputs contain unicode characters? How would you adapt your solution to such case?
//
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        for(auto& a : s)
            mp[a]++;
        for(auto& a : t)
            if(mp.find(a)->second > 0)
                --mp[a];
            else
                return false;
        
        
        for(auto& a : mp)
            if(a.second > 0 ) return false;
        
        return true;
    }
};