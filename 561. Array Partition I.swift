/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].

96 ms 100%
*/

class Solution {
    func arrayPairSum(_ nums: [Int]) -> Int {
        var arr=[Int](repeating : 0 , count : 20001)
        for i in nums
        {
            arr[i+10000] += 1
        }
        
        var idx:Int = 0
        var sum:Int = 0
        var cnt:Int = 0
        while cnt < nums.count
        {
            if arr[idx] != 0
            {
                if cnt % 2 == 0
                {
                    sum += idx - 10000
                }
                cnt += 1
                arr[idx] -= 1
            }
            else
            {
                idx += 1
            }
        }
        
        return sum
    }
}