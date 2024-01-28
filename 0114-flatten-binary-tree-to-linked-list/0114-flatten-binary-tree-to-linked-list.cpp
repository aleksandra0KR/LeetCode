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
    void returnNode(TreeNode* root, vector<int>& res){
        if(root == nullptr or (root->left == nullptr and root->right == nullptr)) return;
        if(root->left != nullptr){
            res.push_back(root->left->val);
            returnNode(root->left, res);
        }
        if(root->right != nullptr){
            res.push_back(root->right->val);
            returnNode(root->right, res);
        }

    }
    
    void flatten(TreeNode* root) {
        
        vector<int> res;        
        returnNode(root, res);
        
        for(int a: res){
            root->right = new TreeNode(a);
            root->left = nullptr;
            root = root->right;
        }
    
    }
};