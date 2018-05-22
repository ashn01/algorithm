/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

20 ms  90 %
*/

class Solution {
    func thirdMax(_ nums: [Int]) -> Int {
        var ret:[Int] = [Int.min,Int.min,Int.min]
        
        for num in nums {
            if num == ret[0] || num == ret[1] || num == ret[2] {
                continue
            }
            
            if num > ret[0] {
                ret[2] = ret[1]
                ret[1] = ret[0]
                ret[0] = num
            } else if num > ret[1] {
                ret[2] = ret[1]
                ret[1] = num
            } else if num > ret[2] {
                ret[2] = num
            }
        }
        
        return (ret[2] == Int.min) ? ret[0] : ret[2]
    }
}