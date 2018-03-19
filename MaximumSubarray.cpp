//https://leetcode.com/problems/maximum-subarray/description/
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret=nums[0], sum=0;
        
        for(auto a : nums)
        {
            sum = max(a, sum+a);
            ret = max(ret,sum);
        }
        return ret;
    }
};
