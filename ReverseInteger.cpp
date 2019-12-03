// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:
// 
// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x){
        int reverse = 0;
        int v = x;
        while(v!=0)
        {
            if(reverse > INT_MAX/10 || reverse < INT_MIN/10)
                return 0;
            reverse*=10;
            reverse+=v%10;
            v/=10;
        }
        return reverse;
    }
};
