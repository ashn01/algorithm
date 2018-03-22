//https://leetcode.com/problems/pascals-triangle/description/
//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows)
            return {};
        vector<vector<int>> ret={{1}};
        for(int i=1;i<numRows;i++)
        {
            vector<int> temp={1};
            for(int j=1;j<ret[i-1].size();j++)
                temp.push_back(ret[i-1].at(j)+ret[i-1].at(j-1));
            temp.push_back(1);
            ret.push_back(temp);
        }
        
        return ret;
    }
};
