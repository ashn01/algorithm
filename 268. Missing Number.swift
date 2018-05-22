/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

44 ms 89.66 %
*/

class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        var ret:Int = 0
        for i in 0..<nums.count
        {
            ret^=i^nums[i]
        }
        return ret^nums.count
    }
}