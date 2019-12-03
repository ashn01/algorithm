/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

48 ms  85.71 %
*/
class Solution {
    func findUnsortedSubarray(_ nums: [Int]) -> Int {
        var left:Int = -1
        var right:Int = -2
        var size:Int = nums.count 
        var mini = nums[size-1]
        var maxi = nums[0]
        
        for i in 1..<nums.count {
            maxi = max(maxi, nums[i])
            mini = min(mini, nums[size-i-1])
            if nums[i] < maxi {
                right = i
            }
            if nums[size-1-i] > mini {
                left = size-1-i
            }
        }
        return right - left + 1
    }
}