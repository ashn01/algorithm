//https://leetcode.com/problems/longest-univalue-path/description/
//Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
//Note: The length of path between two nodes is represented by the number of edges between them.
//
//Example 1:
//
//Input:
//
//              5
//             / \
//            4   5
//           / \   \
//          1   1   5
//Output:
//
//2
//Example 2:
//
//Input:
//
//              1
//             / \
//            4   5
//           / \   \
//          4   4   5
//Output:
//
//2
//Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        int ret = 0;
        help(root,ret);
        return ret;
    }
    
    int help(TreeNode* root, int& ret){
        if(root)
        {
            int left=root->left ? help(root->left, ret) : 0;
            int right=root->right ? help(root->right, ret) : 0;

            left = (root->left && root->left->val==root->val) ? left+1 : 0;
            right = (root->right && root->right->val==root->val) ? right+1 : 0;
            ret=max(ret,left+right);
            return max(left,right);
        }
    }
};
