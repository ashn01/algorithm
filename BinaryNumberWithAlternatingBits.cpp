//https://leetcode.com/problems/binary-number-with-alternating-bits/description/
//Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
//
//Example 1:
//Input: 5
//Output: True
//Explanation:
//The binary representation of 5 is: 101
//Example 2:
//Input: 7
//Output: False
//Explanation:
//The binary representation of 7 is: 111.
//Example 3:
//Input: 11
//Output: False
//Explanation:
//The binary representation of 11 is: 1011.
//Example 4:
//Input: 10
//Output: True
//Explanation:
//The binary representation of 10 is: 1010.

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int s=-1;
        while(n>0)
        {
            int val = n%2;
            
            if(val == s)
                return false;
            else
                s=val;
            
            n/=2;
        }
        return true;
    }
};