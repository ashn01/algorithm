//https://leetcode.com/problems/binary-tree-paths/description/
//Given a binary tree, return all root-to-leaf paths.
//
//For example, given the following binary tree:
//
//   1
// /   \
//2     3
// \
//  5
//All root-to-leaf paths are:
//
//["1->2->5", "1->3"]

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
    vector<string> ret;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root)
            make(root,"");
        
        return ret;
    }
    int make(TreeNode* root, string s)
    {
        if(root)
        {
            if(!s.empty())
                s+="->";
            s += to_string(root->val);
            int l = make(root->left,s);
            int r = make(root->right,s);
            if(!l && !r)
            {
                
                ret.push_back(s);
            }
            return 1;
        }
        
        return 0;
    }
};
