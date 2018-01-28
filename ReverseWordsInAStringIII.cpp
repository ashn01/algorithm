//https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
//Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word //order.
//
//Example 1:
//Input: "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"
//Note: In the string, each word is separated by single space and there will not be any extra space in the string.

class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int space=0;
        while(!s.empty())
        {
            space = s.find(' ', 0);
            string temp = s.substr(0,space);
            ret.append(reverseString(temp));
            ret.push_back(' ');
            s.erase(0,space > s.size() ? space : space+1);
        }
        ret.pop_back();
        return ret;
    }
    
    string reverseString(string s) {
        string ret;
        for(int i=s.size()-1;i>=0;i--)
            ret.push_back(s[i]);
        
        return ret;
    }
};