//https://leetcode.com/problems/maximum-average-subarray-i/description/
//Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
//
//Example 1:
//Input: [1,12,-5,-6,50,3], k = 4
//Output: 12.75
//Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
//Note:
//1 <= k <= n <= 30,000.
//Elements of the given array will be in the range [-10,000, 10,000].

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int cur=0;
        int maxV;
        for(int i=0;i<k;i++)
            cur+=nums[i];
        maxV=cur;
        
        for(int i=k;i<nums.size();i++)
        {
            cur = cur+nums[i]-nums[i-k];
            maxV = max(maxV, cur);
        }
        
        return (double) maxV / k;
    }
};
