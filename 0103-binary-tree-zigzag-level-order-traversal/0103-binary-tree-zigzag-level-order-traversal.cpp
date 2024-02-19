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

    
    void nexNoderight(TreeNode* root,  vector<vector<int>>* res, int leavel){
        
       if(root == nullptr) return;
        if(root->right != nullptr and root->left != nullptr){
            if((*res).size() - 1 >= leavel){
                (*res)[leavel].push_back(root->left->val);
                (*res)[leavel].push_back(root->right->val);
                
            }
            else{
                vector<int> temp;
                temp.push_back(root->left->val);
                temp.push_back(root->right->val);
                
                (*res).push_back(temp);
            }
            nexNoderight(root->left, res, leavel + 1);
            nexNoderight(root->right, res, leavel + 1);
            return;
        }
        else if(root->right != nullptr){
            if((*res).size()  - 1 >= leavel){
                (*res)[leavel].push_back(root->right->val);
            }
            else{
                vector<int> temp;
                temp.push_back(root->right->val);
                (*res).push_back(temp);
            }
            nexNoderight(root->right, res, leavel + 1);
            return;
        }
        else if(root->left != nullptr){
             if((*res).size() - 1 >= leavel){
                (*res)[leavel].push_back(root->left->val);
            }
            else{
                vector<int> temp;
                temp.push_back(root->left->val);
                (*res).push_back(temp);
            }
            nexNoderight(root->left, res, leavel + 1);
            return;
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
       vector<vector<int>> res;
        if(root == nullptr) return res;
        
        if(root->right == nullptr and root->left == nullptr){
            vector<int> temp;
            temp.push_back(root->val);
            res.push_back(temp);
            return res;
        }
        
        vector<int> temp;
        temp.push_back(root->val);
        res.push_back(temp);
        temp.clear();
    
        nexNoderight(root, &res, 1);

       for(int i = 1; i < res.size(); i+=2){
            std::reverse(res[i].begin(), res[i].end());
        }
        
        return res;
    }
};