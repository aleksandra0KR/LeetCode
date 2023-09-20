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
    public List<TreeNode> generateTrees(int n) {
        return helper(1, n);
    }

    List<TreeNode> helper(int left, int right){
        List<TreeNode> res = new ArrayList<>();

        if(left > right) {
            res.add(null);
            return res;
        }

        for(int current = left; current <= right; current++){
            List<TreeNode> l = helper(left, current - 1);
            List<TreeNode> r = helper(current + 1, right);
            for(int i = 0; i < l.size(); i++){
                for(int j = 0; j < r.size(); j++){
                    TreeNode root = new TreeNode(current);
                    root.left = l.get(i);
                    root.right = r.get(j);
                    res.add(root);
                }
            }
        }
        return res;
        
    }

}