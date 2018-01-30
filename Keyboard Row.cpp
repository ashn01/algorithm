//https://leetcode.com/problems/keyboard-row/description/#
//Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
//
//
//American keyboard
//
//
//Example 1:
//Input: ["Hello", "Alaska", "Dad", "Peace"]
//Output: ["Alaska", "Dad"]
//Note:
//You may use one character in the keyboard more than once.
//You may assume the input string will only contain letters of alphabet.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string qwerty[3] = {"qwertyuiopQWERTYUIOP","asdfghjklASDFGHJKL","zxcvbnmZXCVBNM"};
        vector<string> ret;       
        for(string s : words)
        {
            int row=-1;
            bool match = false;
            
            if(s.length() == 1)
            {
                ret.push_back(s);
                continue;
            }
            for(int i=0;i<3;i++)
            {
                if(qwerty[i].find(s[0]) != string::npos)
                {    
                    row = i;
                    break;
                }
            }
            for(int i=1;i<s.length() && row != -1;i++)
            {
                match = true;
                if(qwerty[row].find(s[i]) == string::npos)
                {
                    match = false;
                    break;
                }
            }
            if(match)
                ret.push_back(s);
        }
        return ret;
    }
};