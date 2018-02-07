//https://leetcode.com/problems/monotone-increasing-digits/description/
//Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
//
//(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
//
//Example 1:
//Input: N = 10
//Output: 9
//Example 2:
//Input: N = 1234
//Output: 1234
//Example 3:
//Input: N = 332
//Output: 299
//Note: N is an integer in the range [0, 10^9].

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int temp = str.length();
        for(int i=temp-1;i>0;i--)
        {
            if(str[i] < str[i-1])
            {
                temp = i;
                --str[i-1];
            }
        }
        
        for(int i=temp;i<str.length();i++)
            str[i]='9';
        
        return stoi(str);
    }
};