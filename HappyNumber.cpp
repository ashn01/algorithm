//https://leetcode.com/problems/happy-number/description/
//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 19 is a happy number
//
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1

class Solution {
    set<int> s;
public:
    bool isHappy(int n) {
        int val = n;
        s.insert(val);
        while(true)
        {   
            if(val == 1) return true;
            int next =0;
            while(val)
            {
                int temp = val%10;
                next += temp*temp;
                val/=10;
            }
            val=next;
            if(s.find(val) != s.end())
                return false;
            s.insert(val);
        }
        
    }
};

