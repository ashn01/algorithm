//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode* root) {
        if(root)
        {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            
            if(root->left && root->right)
                return min(left,right)+1;
            else
                return max(left,right)+1;
        }
        return 0;
    }
};
