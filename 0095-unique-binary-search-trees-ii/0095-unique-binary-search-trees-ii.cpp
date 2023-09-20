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

    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }

    vector<TreeNode*> helper(int left, int right){
        vector<TreeNode*> res;

        if(left > right) {
            res.push_back(nullptr);
            return res;
        }

        if(left == right){
            res.push_back(new TreeNode(left));
            return res;
        }

        for(int current = left; current <= right; current++){
            vector<TreeNode*> l = helper(left, current - 1);
            vector<TreeNode*> r = helper(current + 1, right);
            for(int i = 0; i < l.size(); i++){
                for(int j = 0; j < r.size(); j++){
                    TreeNode* root = new TreeNode(current);
                    root->left = l[i];
                    root->right = r[j];
                    res.push_back(root);
                }
            }
        }
        return res;
        
    }

};
