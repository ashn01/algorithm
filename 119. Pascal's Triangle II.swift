/*
Given a non-negative index k where k ¡Â 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

12 ms 95 %
*/
class Solution {
    func getRow(_ rowIndex: Int) -> [Int] {
        if rowIndex == 0
        {
            return [1]
        }
        
        var ret:[Int] = [1,1]
        for i in 1..<rowIndex
        {
            let temp = ret
            for j in 1..<ret.count
            {
                ret[j] = temp[j-1]+temp[j]
            }
            ret.append(1)
        }
        
        return ret
    }
}