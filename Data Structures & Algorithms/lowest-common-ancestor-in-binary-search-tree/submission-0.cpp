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
    bool buildPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(!root) return false;
        path.push_back(root);
        if(root == target) return true;
        bool left = buildPath(root->left, target, path);
        bool right = buildPath(root->right, target, path);
        if(left || right) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        if(!buildPath(root, p, path1)|| !buildPath(root,q, path2)) return nullptr;

        TreeNode* lca = nullptr;
        for(int i = 0; i<min(path1.size(), path2.size()); i++){
            if(path1[i] == path2[i]) lca = path1[i];
            else break;
        }
        return lca;
    }
};
