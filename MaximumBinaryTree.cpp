//https://leetcode.com/problems/maximum-binary-tree/description/
//Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
//
//The root is the maximum number in the array.
//The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
//The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
//Construct the maximum tree by the given array and output the root node of this tree.
//
//Example 1:
//Input: [3,2,1,6,0,5]
//Output: return the tree root node representing the following tree:
//
//      6
//    /   \
//   3     5
//    \    / 
//     2  0   
//       \
//        1
//Note:
//The size of the given array will be in the range [1,1000].


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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int max = 0;
        int idx=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] > max)
            {
                max = nums[i];
                idx=i;
            }
        
        TreeNode* ret = new TreeNode(nums[idx]);
        make(nums, ret->left, 0, idx);
        make(nums, ret->right, idx+1, nums.size());
        return ret;   
    }
    
    void make(vector<int>& nums, TreeNode*& subRoot, int from, int to)
    {
        if(from == to)
            return;
        int max = -1;
        int idx=-1;
        for(int i=from;i<to;i++)
            if(nums[i] > max)
            {
                max = nums[i];
                idx=i;
            }
        subRoot = new TreeNode(nums[idx]);
        if(from != idx)
            make(nums, subRoot->left, from, idx);
        if(idx+1  != to)
            make(nums, subRoot->right, idx+1, to);
    }
    /*void deletion(TreeNode*& ohs)
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