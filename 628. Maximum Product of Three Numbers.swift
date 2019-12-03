/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

220 ms  81.25%
*/
class Solution {
    func maximumProduct(_ nums: [Int]) -> Int {
        let sortedNum = nums.sorted(by: >)
        return max(sortedNum[0] * sortedNum[1] * sortedNum[2], sortedNum[0] * sortedNum[nums.count-1] * sortedNum[nums.count-2])
    }
}