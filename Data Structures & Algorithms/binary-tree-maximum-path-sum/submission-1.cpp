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
    int maxPath = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int lh = max(solve(root->left), 0);
        int rh = max(solve(root->right), 0);

        maxPath = max(maxPath, root->val + lh + rh);

        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxPath;
    }
};
