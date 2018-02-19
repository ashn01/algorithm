//
//Find the sum of all left leaves in a given binary tree.
//
//Example:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        if(root)
        {
            ret = root->left && !root->left->left && !root->left->right ? root->left->val : sumOfLeftLeaves(root->left);
            ret += root->right ? sumOfLeftLeaves(root->right) : 0;
        }
        return ret;
    }
};