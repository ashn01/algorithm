/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
20 ms 92.17%
*/

class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var curr:Int = 0
        var ret:Int = Int.min
        
        for i in nums
        {
            curr+=i
            if i > curr
            {
                curr = i
            }
            if curr > ret
            {
                ret = curr
            }
        }
        
        return ret
    }
}