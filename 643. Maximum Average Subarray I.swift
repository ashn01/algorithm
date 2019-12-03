/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

152 ms  87.50 %
*/
class Solution {
    func findMaxAverage(_ nums: [Int], _ k: Int) -> Double {
        var ret = 0
        var cnt = 0
        for i in 0..<k
        {
            ret += nums[i]
        }
        var temp = ret
        for i in k..<nums.count
        {
            temp += nums[i] - nums[cnt]
            ret = max(ret,temp)
            cnt += 1
        }
        
        return Double(ret) / Double(k)
    }
}