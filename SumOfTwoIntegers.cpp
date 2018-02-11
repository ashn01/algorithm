//https://leetcode.com/problems/sum-of-two-integers/description/
// reference : https://stackoverflow.com/questions/4068033/add-two-integers-using-only-bitwise-operators
//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
//Example:
//Given a = 1 and b = 2, return 3.

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0)
            return a;

        return getSum( a ^ b, (a & b) << 1);
    }
};

/*
 * a = 3, b = 5;
 * a ^ b = 6, a & b << 1 = 2
 * a ^ b = 4, a & b << 1 = 4
 * a ^ b = 0, a & b << 1 = 8
 * a ^ b = 8, a & b << 1 = 0
*/