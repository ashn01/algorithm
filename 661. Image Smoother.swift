/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].

364 ms 62.50 %
*/
class Solution {
    func imageSmoother(_ M: [[Int]]) -> [[Int]] {
        var ret = M
        let xMax = M[0].count
        let yMax = M.count
        let loc:[[Int]] = [[-1,-1],[-1,0],[-1,1],[0,-1],[0,0],[0,1],[1,-1],[1,0],[1,1]]
        
        for i in 0..<yMax
        {
            for j in 0..<xMax
            {
                var temp:Int = 0
                var cnt:Int = 0
                for k in loc
                {
                    if let y:Int = i + k[0], let x:Int = j + k[1], y >= 0 && x >= 0 && y < yMax && x < xMax 
                    {
                        temp += M[y][x]
                        cnt += 1
                    }
                }
                ret[i][j] = temp / cnt
            }
        }
        
        return ret
    }
}