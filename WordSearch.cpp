//https://leetcode.com/problems/word-search/description/
//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. //The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> track=board;
        char* w = &word[0];
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                //track = board;
                bool ret = false;
                if(board[i][j] == *w)
                {
                    if(word.length() == 1)
                        return true;
                    ret = directions(board,j,i,w,track);
                    if(ret)
                        return ret;
                }
            }
        }
        return false;
    }
    
    bool directions(vector<vector<char>>& board,int y, int x, char *w, vector<vector<char>>& track)
    {
        bool ret=false;
        if( x <0 || x >= board.size() || y < 0 || y >= board[0].size() || track[x][y] == '-' || *w != board[x][y])
        {
            return false;
        }
        
        if(*(w+1) == '\0' )
        {
            return true;
        }
        
        track[x][y] = '-';
        
        if(directions(board,y-1,x,w+1,track) || 
           directions(board,y+1,x,w+1,track) ||
           directions(board,y,x-1,w+1,track) || 
           directions(board,y,x+1,w+1,track))
            return true;
        
        track[x][y] = board[x][y];
        
        return ret;
    }
};
