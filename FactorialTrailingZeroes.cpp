//https://leetcode.com/problems/factorial-trailing-zeroes/description/
//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.

class Solution {
public:
    int trailingZeroes(int n) {
        return n/5 > 0 ? trailingZeroes(n/5) + n/5 : 0;
    }
};
