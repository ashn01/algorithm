//https://leetcode.com/problems/symmetric-tree/description/
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3

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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return find(root->left,root->right);
    }
    
    bool find(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
        else if((!l && r) || (l && !r))
            return false;
        else if(l->val != r->val)
            return false;
        return find(l->left,r->right) && find(l->right, r->left);
    }
};
