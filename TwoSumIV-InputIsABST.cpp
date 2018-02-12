//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
//Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
//Example 1:
//Input: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 9
//
//Output: True
//Example 2:
//Input: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 28
//
//Output: False

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
    bool findTarget(TreeNode* root, int k) {
        return main(root,root->left,k) || main(root,root->right,k);
    }
    
    bool main(TreeNode* mainRoot, TreeNode* curRoot, int k)
    {
        if(curRoot)
        {
            if(!find(mainRoot,curRoot->val,k - curRoot->val))
                return main(mainRoot, curRoot->left, k) || main(mainRoot, curRoot->right, k);
            else
                return true;
        }
        return false;
    }
    
    bool find(TreeNode* root,int occupied, int k)
    {
        if(root)
        {
            if(root->val == k && k != occupied)
                return true;
            else if(root->val > k)
                return find(root->left,occupied,k);
            else
                return find(root->right,occupied,k);
        }
        return false;
    }
};
