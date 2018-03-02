//https://leetcode.com/problems/image-smoother/description/
//Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
//
//Example 1:
//Input:
//[[1,1,1],
// [1,0,1],
// [1,1,1]]
//Output:
//[[0, 0, 0],
// [0, 0, 0],
// [0, 0, 0]]
//Explanation:
//For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
//For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
//For the point (1,1): floor(8/9) = floor(0.88888889) = 0
//Note:
//The value in the given matrix is in the range of [0, 255].
//The length and width of the given matrix are in the range of [1, 150].


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ret(M.size(), vector<int>(M[0].size(),0));
        vector<pair<int,int>> pr({{-1,-1},{-1,0},{-1,+1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,+1}});
        
        for(int i=0;i<ret.size();i++)
        {
            for(int j=0;j<ret[i].size();j++)
            {
                int temp=0;
                int cnt=0;
                for(auto& a : pr)
                    if(i+a.first >= 0 && i+a.first < ret.size() && j+a.second >= 0 && j+a.second < ret[i].size())
                    {
                        temp += M[i+a.first][j+a.second];
                        cnt++;
                    }
                
                ret[i][j] = temp/cnt;
                    
            }
        }
        
        
        return ret;
    }
};



