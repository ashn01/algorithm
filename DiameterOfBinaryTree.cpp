//https://leetcode.com/problems/diameter-of-binary-tree/description/
//Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//
//Example:
//Given a binary tree 
//          1
//         / \
//        2   3
//       / \     
//      4   5    
//Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
//Note: The length of path between two nodes is represented by the number of edges between them.

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
    int longest=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return longest;
    }
    int depth(TreeNode* root)
    {
        if(root)
        {
            int left = depth(root->left);
            int right = depth(root->right);
            if(longest < left+right)
                longest = left+right;
            return max(left,right)+1;
        }
        return 0;
    }
};