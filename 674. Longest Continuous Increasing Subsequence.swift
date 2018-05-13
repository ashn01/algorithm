/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.

20 ms 100 %
*/
class Solution {
    func findLengthOfLCIS(_ nums: [Int]) -> Int {
        var ret = 1
        var long = 1
        if nums.count == 0
        {
            return 0
        }
        for i in 1..<nums.count
        {
            if nums[i] > nums[i-1]
            {
                long += 1
            }
            else
            {
                if ret < long
                {
                    ret = long
                }
                long = 1
            }
        }
        return max(ret,long)
    }
}