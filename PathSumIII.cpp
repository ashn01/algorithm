//https://leetcode.com/problems/path-sum-iii/description/
//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
//The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
//Example:
//
//root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. -3 -> 11

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
    vector<int> ret;
public:
    int pathSum(TreeNode* root, int sum) {
        return find(root,sum);
    }
    int find(TreeNode* root, int t)
    {
        if(root)
        {
            int cnt= root->val == t ? 1 : 0;
            for_each(ret.begin(),ret.end(),[&](int& i){
                if((i+=root->val)==t)
                    cnt++;
            });
            ret.push_back(root->val);
            cnt += find(root->left,t) + find(root->right,t);
            ret.pop_back();
            for_each(ret.begin(),ret.end(),[&](int& i){
                i-=root->val;
            });
            return cnt;
        }
        return 0;
    }
};
