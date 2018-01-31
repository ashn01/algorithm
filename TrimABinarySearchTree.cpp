//https://leetcode.com/problems/trim-a-binary-search-tree/description/
//Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

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
    TreeNode* ret;
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(L == R)
        {
            ret = new TreeNode(L);
            return ret;
        }
        make(root,ret,L,R);
        
        return ret;
    }
    
    void make(TreeNode* root, TreeNode*& ret, const int L, const int R)
    {
        if(root == nullptr)
            return;
        if(root->val >= L && root->val <= R)
        {
            cout<<root->val<<endl;
            ret = new TreeNode(root->val);
            make(root->left,ret->left,L,R);
            make(root->right,ret->right,L,R);
        }
        else
        {
            make(root->left,ret,L,R);
            make(root->right,ret,L,R);
        }
    }
/*  void deletion(TreeNode*& ohs)
    {
        if(ohs != nullptr)
        {
            if(ohs->left != nullptr)
            {
                deletion(ohs->left);
            }
            if(ohs->right != nullptr)
            {
                deletion(ohs->right);
            }
            if(ohs->left == nullptr && ohs->right == nullptr)
            {
                cout << "delete : " << ohs->val<<endl;
                delete ohs;
                ohs = nullptr;
            }
        }
    }
    ~Solution()
    {
        deletion(ret);
    }*/
};