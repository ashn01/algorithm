//https://leetcode.com/problems/longest-palindrome/description/
//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//
//Note:
//Assume the length of given string will not exceed 1,010.
//
//Example:
//
//Input:
//"abccccdd"
//
//Output:
//7
//
//Explanation:
//One longest palindrome that can be built is "dccaccd", whose length is 7.



class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto& a : s)
            mp[a]++;
        int ret=0;
        bool sch = false;
        
        for(auto& a : mp)
        {
            ret+=a.second;
            if(a.second % 2 == 1)
            {
                ret--;
                sch = true;
            }
        }
        
        return sch ? ret+1 : ret;
    }
};
