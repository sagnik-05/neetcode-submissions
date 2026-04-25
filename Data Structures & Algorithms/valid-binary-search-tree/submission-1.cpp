/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool flag = true;
    long long prev = LONG_MIN;
    void solve(TreeNode* root){
        if(root->left) solve(root->left);

        
            if(root->val<=prev){
                flag = false;
                return ;
            }
    
        prev = root->val;

        if(root->right) solve(root->right);

    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return flag;
    }
};
