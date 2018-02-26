//https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
//Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
//Example:
//
//Input:
//
//   1
//    \
//     3
//    /
//   2
//
//Output:
//1
//
//Explanation:
//The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
//Note: There are at least two nodes in this BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    int smallest = INT_MAX, temp = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        if (root->left != nullptr) 
            getMinimumDifference(root->left);
        
        if (temp >= 0) 
            smallest = min(smallest, root->val - temp);
        temp = root->val;
        
        if (root->right != nullptr) 
            getMinimumDifference(root->right);
        return smallest;
    }
};