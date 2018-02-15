//https://leetcode.com/problems/range-addition-ii/description/
//Given an m * n matrix M initialized with all 0's and several update operations.
//
//Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
//
//You need to count and return the number of maximum integers in the matrix after performing all the operations.
//
//Example 1:
//Input: 
//m = 3, n = 3
//operations = [[2,2],[3,3]]
//Output: 4
//Explanation: 
//Initially, M = 
//[[0, 0, 0],
// [0, 0, 0],
// [0, 0, 0]]
//
//After performing [2,2], M = 
//[[1, 1, 0],
// [1, 1, 0],
// [0, 0, 0]]
//
//After performing [3,3], M = 
//[[2, 2, 1],
// [2, 2, 1],
// [1, 1, 1]]
//
//So the maximum integer in M is 2, and there are four of it in M. So return 4.
//Note:
//The range of m and n is [1,40000].
//The range of a is [1,m], and the range of b is [1,n].
//The range of operations size won't exceed 10,000.

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minR=m, minC=n;

        for(auto& r : ops)
        {
            if(r[0] < minR)
                minR = r[0];
            if(r[1] < minC)
                minC = r[1];
        }
        
        return minR*minC;
    }
};