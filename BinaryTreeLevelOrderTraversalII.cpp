//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its bottom-up level order traversal as:
//[
//  [15,7],
//  [9,20],
//  [3]
//]

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
        vector<vector<int>> ret;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root)
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int size=q.size();
                vector<int> temp;
                for(int i=0;i<size;i++)
                {   
                    TreeNode* t = q.front();
                    temp.push_back(t->val);
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                    q.pop();
                }
                ret.push_back(temp);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
