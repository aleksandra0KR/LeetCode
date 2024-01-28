/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    void returnNode(TreeNode root, List<Integer> res){
        if(root == null || (root.left == null && root.right == null)) return;
        if(root.left != null){
            res.add(root.left.val);
            returnNode(root.left, res);
        }
        if(root.right != null){
            res.add(root.right.val);
            returnNode(root.right, res);
        }

    }
    
    void flatten(TreeNode root) {
        
        List<Integer> res = new ArrayList<>(); 
        returnNode(root, res);
        
        for(int a: res){
            root.right = new TreeNode(a);
            root.left = null;
            root = root.right;
        }
    
    }
}