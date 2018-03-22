//https://leetcode.com/problems/ugly-number/description/
//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//
//Note:
//
//1 is typically treated as an ugly number.
//Input is within the 32-bit signed integer range.

class Solution {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++)
            while (num%i == 0)
                num/=i;
        return num == 1;
    }
};
