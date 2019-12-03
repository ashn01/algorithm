/*
 Implement strStr().
 
 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Example 1:
 
 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:
 
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 Clarification:
 
 What should we return when needle is an empty string? This is a great question to ask during an interview.
 
 For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        int size = haystack.length();
        
        if(needle == "")
            return 0;
        
        if(len > size)
            return -1;
        
        int cnt=0;
        int index=-1;
        
        for(int i = 0 ;i<size;i++)
        {
            if(needle[cnt] == haystack[i])
            {
                cnt++;
                if(index == -1)
                    index = i;
            }
            else
            {
                i-=cnt;
                cnt = 0;
                index = -1;
            }
            if(cnt == len)
                return index;
        }
        
        return cnt == len ? index : -1;
    }
};
