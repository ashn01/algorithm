//https://leetcode.com/problems/detect-capital/description/
//Given a word, you need to judge whether the usage of capitals in it is right or not.
//
//We define the usage of capitals in a word to be right when one of the following cases holds:
//
//All letters in this word are capitals, like "USA".
//All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital if it has more than one letter, like "Google".
//Otherwise, we define that this word doesn't use capitals in a right way.
//Example 1:
//Input: "USA"
//Output: True
//Example 2:
//Input: "FlaG"
//Output: False
//Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

class Solution {
public:
    bool detectCapitalUse(string word) {
        int mask = word[0] <= 90 ? 1 : 0;
        for(int i=1; i<word.length();i++)
        {
            if( !mask && word[i] >= 97)
                continue;
            if(mask > 0 && word[i] <= 90)
            {
                mask++;
                continue;
            }
            if(mask == 1 && word[i] >= 97)
                continue;
            
            return false;
        }
        
        
        return mask == 1 || mask == word.length() || mask == 0 ? true : false;
    }
};
