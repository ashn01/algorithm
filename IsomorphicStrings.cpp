//https://leetcode.com/problems/isomorphic-strings/description/
//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char a[128]={0};
        char b[128]={0};
        
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]] != b[t[i]])
                return false;
            a[s[i]]+=i+1;
            b[t[i]]+=i+1;
        }
        return true;
    }
};
