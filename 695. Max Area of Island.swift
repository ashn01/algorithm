/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
52ms 93.55%
*/

class Solution {
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
        var area = 0
        var vGrid = grid
        for i in 0 ... vGrid.count-1
        {
            for j in 0 ... vGrid[0].count-1
            {
                if vGrid[i][j] == 1, let ret:Int = calcArea(&vGrid,i,j), ret > area
                {
                    area = ret
                }
            }
        }
        return area
    }
    
    func calcArea(_ grid:inout [[Int]], _ x:Int, _ y:Int)->Int
    {
        if x < 0 || y < 0 || x == grid.count || y == grid[0].count
        {
            return 0
        }
        if grid[x][y] == 1
        {
            grid[x][y] = 2
            return 1 + calcArea(&grid,x+1,y) + calcArea(&grid,x-1,y) + calcArea(&grid,x,y+1) + calcArea(&grid,x,y-1)
        }
        return 0
    }
}