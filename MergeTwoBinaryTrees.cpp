/* https://leetcode.com/problems/merge-two-binary-trees/description/
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 *
 * You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 *
 * Example 1:
 * Input: 
 *	Tree 1                     Tree 2                  
 *        1                         2                             
 *       / \                       / \                            
 *      3   2                     1   3                        
 *     /                           \   \                      
 *    5                             4   7                  
 * Output: 
 * Merged tree:
 *	     3
 *	    / \
 *	   4   5
 *	  / \   \ 
 *	 5   4   7
 * Note: The merging process must start from the root nodes of both trees.
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
private:
    TreeNode* ret;    
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 != nullptr && t2 != nullptr)
        {
            ret = new TreeNode(t1->val+t2->val);
            leftHand(t1->left,t2->left,ret->left);
            rightHand(t1->right,t2->right,ret->right);
        }
        else if(t1 != nullptr && t2 == nullptr)
        {
            ret = new TreeNode(t1->val);
            leftHand(t1->left,nullptr,ret->left);
            rightHand(t1->right,nullptr,ret->right);
        }
        else if(t1 == nullptr && t2 != nullptr)
        {
            ret = new TreeNode(t2->val);
            leftHand(nullptr,t2->left,ret->left);
            rightHand(nullptr,t2->right,ret->right);
        }
        return ret;
    }
    
    void leftHand(const TreeNode* t1, const TreeNode* t2, TreeNode*& lh)
    {
        if(t1 != nullptr && t2 != nullptr)
        {
            lh = new TreeNode(t1->val+t2->val);
            leftHand(t1->left, t2->left,lh->left);
            rightHand(t1->right, t2->right,lh->right);
        }
        else if(t1 != nullptr && t2 == nullptr)
        {
            lh = new TreeNode(t1->val);
            leftHand(t1->left, nullptr,lh->left);
            rightHand(t1->right, nullptr,lh->right);
        }
        else if(t1 == nullptr && t2 != nullptr)
        {
            lh = new TreeNode(t2->val);
            leftHand(nullptr, t2->left,lh->left);
            rightHand(nullptr, t2->right,lh->right);
        }
    }
    
    void rightHand(const TreeNode* t1, const TreeNode* t2, TreeNode*& rh)
    {
        if(t1 != nullptr && t2 != nullptr)
        {
            rh = new TreeNode(t1->val+t2->val);
            leftHand(t1->left, t2->left,rh->left);
            rightHand(t1->right, t2->right,rh->right);
        }
        else if(t1 != nullptr && t2 == nullptr)
        {
            rh = new TreeNode(t1->val);
            leftHand(t1->left, nullptr,rh->left);
            rightHand(t1->right, nullptr,rh->right);
        }
        else if(t1 == nullptr && t2 != nullptr)
        {
            rh = new TreeNode(t2->val);
            leftHand(nullptr, t2->left,rh->left);
            rightHand(nullptr, t2->right,rh->right);
        }
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

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* t1 = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* t2 = stringToTreeNode(line);
        
        TreeNode* ret = Solution().mergeTrees(t1, t2);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

