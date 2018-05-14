/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

12 ms  96.23 %
*/
class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var ret:[[Int]] = [[1]]
        
        if numRows == 0
        {
            return []
        }
        
        for i in 1..<numRows
        {
            var temp:[Int] = [1]
            let ref = ret[i-1]
            for j in 0..<ret[i-1].count-1
            {
                temp.append(ref[j]+ref[j+1])    
            }
            
            temp.append(1)
            ret.append(temp)
        }
        
        return ret
    }
}