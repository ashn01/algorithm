//https://leetcode.com/problems/pascals-triangle-ii/description/
//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret={1};
        for(int i=0;i<rowIndex;i++)
        {
            for(int j=ret.size()-1; j>0;j--)
                ret[j] += ret[j-1];
            ret.push_back(1);
        }
        return ret;
    }
};
