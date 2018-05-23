/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.


12 ms  100 %
*/
class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var i = 0
        var j = numbers.count - 1
        var ret:[Int] = []
        
        while i < j
        {
            let temp = numbers[i] + numbers[j]
            if temp == target
            {
                ret.append(i+1)
                ret.append(j+1)
                break
            }
            else if temp > target
            {
                j -= 1
            }
            else
            {
                i += 1
            }
        }
        
        return ret
    }
}