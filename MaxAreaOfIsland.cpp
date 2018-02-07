//https://leetcode.com/problems/max-area-of-island/description/#
//Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
//Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
//Example 1:
//[[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
//Example 2:
//[[0,0,0,0,0,0,0,0]]
//Given the above grid, return 0.
//Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret=0;
        int temp = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    temp = calcArea(grid,i,j);
                    if(temp > ret)
                        ret = temp;
                }
            }
        }
        return ret;
    }
    
    int calcArea(vector<vector<int>>& grid, int x, int y)
    {
        int ret=1;
        if(x > 0 && grid[x-1][y] == 1) // N
        {
            grid[x-1][y] = 2;
            ret += calcArea(grid,x-1,y);
        }
        if(x < grid.size()-1 && grid[x+1][y] == 1) // S
        {
            grid[x+1][y] = 2;
            ret += calcArea(grid,x+1,y);
        }
        if(y > 0 && grid[x][y-1] == 1) // W
        {
            grid[x][y-1] = 2;
            ret += calcArea(grid,x,y-1);
        }
        if(y < grid[0].size()-1 && grid[x][y+1] == 1) // E
        {
            grid[x][y+1] = 2;
            ret += calcArea(grid,x,y+1);
        }
            
        return ret;   
    }
};
