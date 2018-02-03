//https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
//Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
//Example 1:
//Input:
//    3
//   / \
//  9  20
//    /  \
//   15   7
//Output: [3, 14.5, 11]
//Explanation:
//The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
//Note:
//The range of node's value is in the range of 32-bit signed integer.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            double value=sum(q);
            ret.push_back(value);
        }
        return ret;
    }
    
    double sum(queue<TreeNode*>& q)
    {
        int size = q.size();
        double sum = 0;
        for(int i=0;i<size;i++)
        {
            if(q.front()->left != nullptr)
                q.push(q.front()->left);
            if(q.front()->right != nullptr)
                q.push(q.front()->right);
            sum += q.front()->val;
            q.pop();
        }
        
        return sum/size;
    }
};