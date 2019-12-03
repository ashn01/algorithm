/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

20 ms  94.61 %
*/

class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var prevIdx = -1
        for i in 0..<nums.count
        {
            if nums[i] == 0 && prevIdx == -1
            {
                prevIdx = i
            }
            else if nums[i] != 0 && prevIdx != -1
            {
                nums[prevIdx] = nums[i]
                nums[i] = 0
                prevIdx = prevIdx + 1 == i ? i : prevIdx + 1
            }
        }
    }
}
