/*
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 Example:
 
 Input: "Hello World"
 Output: 5
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        bool check=false;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i] != ' ')
                cnt++;
            else if(cnt != 0)
                return cnt;
        }
        
        return cnt;
    }
};
