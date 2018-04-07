//https://leetcode.com/problems/add-binary/description/
//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        
        int as=a.length()-1, bs=b.length()-1;
        string ret = "";
        int val=0;
        bool up=false;
        
        while(as>=0 || bs>= 0)
        {
            val += as >= 0 ? a[as--] - '0':0;
            val += bs >= 0 ? b[bs--] - '0':0;
            val += up ? 1 : 0;
            ret = char(val%2+'0')+ret;
            up = val >= 2 ? true : false;
            val=0;
        }
        
        if(up)
            ret = '1'+ret;
        
        return ret;
    }
};
