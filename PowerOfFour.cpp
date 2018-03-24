//https://leetcode.com/problems/power-of-four/description/
//Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
//Example:
//Given num = 16, return true. Given num = 5, return false.

class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num && (num % 4 == 0))
            num /= 4;
            
        return num == 1;
    }
};


