//https://leetcode.com/problems/plus-one/description/
//Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool check=false;
        digits[digits.size()-1]++;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i] == 10)
            {
                if(i > 0)
                {
                    digits[i-1]++;
                    digits[i]=0;
                }
                else
                {
                    digits[i] = 1;
                    digits.push_back(0);
                }
                check = true;
            }
            else
                break;
        }
        return digits;
    }
};
