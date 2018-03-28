//https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
//Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//Both the left and right subtrees must also be binary search trees.
//For example:
//Given BST [1,null,2,2],
//   1
//    \
//     2
//    /
//   2
//return [2].
//
//Note: If a tree has more than one mode, you can return them in any order.

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
    vector<int> findMode(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ret;
        unordered_map<int,int> mp;
        int mod = mode(root,mp);
        
        for(auto& a : mp)
            if(a.second == mod)
                ret.push_back(a.first);
        
        return ret;
    }
    
    int mode(TreeNode* root, unordered_map<int,int>& mp)
    {
        if(root)
        {
            mp[root->val]++;
            return max(mp[root->val], max(mode(root->left, mp), mode(root->right,mp)));
        }
        return 0;
    }
    
};
