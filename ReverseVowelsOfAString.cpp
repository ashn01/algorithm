//https://leetcode.com/problems/reverse-vowels-of-a-string/description/
//Write a function that takes a string as input and reverse only the vowels of a string.
//
//Example 1:
//Given s = "hello", return "holle".
//
//Example 2:
//Given s = "leetcode", return "leotcede".
//
//Note:
//The vowels does not include the letter "y".

class Solution {
public:
    string reverseVowels(string s) {
        string vow="aeiouAEIOU";
        for(int i=0, j = s.length()-1; i < j && j > i; )
        {
            if(vow.find(s[i]) != string::npos && vow.find(s[j]) != string::npos)
                swap(s[i++],s[j--]);
            
            if(vow.find(s[i]) == string::npos)
                ++i;
            if(vow.find(s[j]) == string::npos)
                --j;
        }
        return s;
    }
};
