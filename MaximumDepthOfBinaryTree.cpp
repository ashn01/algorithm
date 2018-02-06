//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its depth = 3.

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
    int maxDepth(TreeNode* root) {
        return subNode(root,0);
    }
    int subNode(TreeNode*& subRoot, int level)
    {
        int lh, rh;
        lh = rh = level;
        if(subRoot != nullptr)
        {
            lh = subNode(subRoot->left,++lh);
            rh = subNode(subRoot->right,++rh);
        }
        return max(lh,rh);
    }
};