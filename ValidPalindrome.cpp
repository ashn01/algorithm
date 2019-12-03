/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
 Note: For the purpose of this problem, we define empty string as valid palindrome.
 
 Example 1:
 
 Input: "A man, a plan, a canal: Panama"
 Output: true
 Example 2:
 
 Input: "race a car"
 Output: false
 */

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")
            return true;
        return helper(s,0,s.length()-1);
    }
    bool helper(string &s, int pre, int post)
    {
        bool checker=false;
        if(pre > post)
            return true;
        if(s[pre] < 48 || (s[pre] > 57 && s[pre] <65) || (s[pre] > 90 && s[pre] < 97) || s[pre] > 122)
        {
            pre++;
            checker=true;
        }
        if(s[post] < 48 || (s[post] > 57 && s[post] <65) || (s[post] > 90 && s[post] < 97) || s[post] > 122)
        {
            post--;
            checker=true;
        }
        if (checker)
            return helper(s,pre,post);
        else
        {
            if(s[pre] <= 90)
                s[pre]+=32;
            if(s[post] <= 90)
                s[post]+=32;
            if(s[pre] == s[post])
                if(pre==post || pre+1==post)
                    return true;
                else
                    return helper(s,++pre,--post);
                else
                    return false;
        }
    }
};
