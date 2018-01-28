//https://leetcode.com/problems/reverse-string/description/
//Write a function that takes a string as input and returns the string reversed.
//
//Example:
//Given s = "hello", return "olleh".

class Solution {
public:
    string reverseString(string s) {
        string ret;
        for(int i=s.size()-1;i>=0;i--)
            ret.push_back(s[i]);
        
        return ret;
    }
};