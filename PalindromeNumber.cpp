//https://leetcode.com/problems/palindrome-number/description/
//Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 )
            return false;
        
        int reverse=0,origin = x;
        while(origin > 0)
        {
            reverse*=10;
            reverse += origin%10;
            origin/=10;
        }
        
        return reverse == x;
    }
};
