/*
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 

Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 

Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].

16 ms 94.12 %
*/

class Solution {
    func dominantIndex(_ nums: [Int]) -> Int {
        var b = 0
        var sb = 0
        var idx = 0
        for i in 0..<nums.count
        {
            if nums[i] > b
            {
                sb = b
                b = nums[i]
                idx = i
            }
            else if nums[i] > sb
            {
                sb = nums[i]
            }
        }
        return sb * 2 <= b ? idx : -1
    }
}