/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret="";
        
        if(strs.size() == 0 || strs[0] == "")
            return ret;
        if(strs.size() == 1)
            return strs[0];
        
        int len = strs[0].length();
        int size = strs.size();
        
        for(int i=0;i < len;i++)
        {
            for(int j=0;size > j+1 ;j++)
            {
                if(strs[j][i] != strs[j+1][i] )
                    return ret;
            }
            ret+=strs[0][i];
        }
        return ret;
    }
};
