//https://leetcode.com/problems/maximum-product-of-three-numbers/description/
//Given an integer array, find three numbers whose product is maximum and output the maximum product.
//
//Example 1:
//Input: [1,2,3]
//Output: 6
//Example 2:
//Input: [1,2,3,4]
//Output: 24
//Note:
//The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
//Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxArr[]={-10000,-10000,-10000};
        int minArr[]={10000,10000};
        for(auto& a : nums)
        {
            for(int i=0;i<3;i++)
                if(maxArr[i] < a)
                {
                    for(int j=2;j>i;j--)
                        maxArr[j] = maxArr[j-1];
                    maxArr[i] = a;
                    break;
                }
            for(int i=0;i<2;i++)
                if(minArr[i] > a)
                {
                    for(int j=1;j>i;j--)
                        minArr[j] = minArr[j-1];
                    minArr[i] = a;
                    break;
                }
        }
        
        
        return max(maxArr[0]*maxArr[1]*maxArr[2], maxArr[0]*minArr[0]*minArr[1]);
    }
};