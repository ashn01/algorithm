//https://leetcode.com/problems/number-of-segments-in-a-string/description/
//Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
//
//Please note that the string does not contain any non-printable characters.
//
//Example:
//
//Input: "Hello, my name is John"
//Output: 5

class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0)
            return 0;
        int ret = 0;
        bool yes=false;
        for(int i =0 ;i<s.size();i++)
        {
            if(s[i] != ' ')
                yes = true;
            if(s[i] == ' ' && yes)
            {
                ret++;
                yes = false;
            }
        }
        return yes ? ret+1 : ret;
    }
};
