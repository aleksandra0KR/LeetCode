/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func generateTrees(n int) []*TreeNode {
        return helper(1, n)
    }

    func helper(left, right int)[]*TreeNode{
        var res []*TreeNode

        if(left > right) {
            res = append(res, nil)
            return res
        }

        for current := left; current <= right; current++{
            l := helper(left, current - 1)
            r := helper(current + 1, right)
            for i := 0; i < len(l); i++{
                for j := 0; j < len(r); j++{
                    currentTree := &TreeNode{Val: current, Left: l[i], Right: r[j]}
                    res = append(res, currentTree)
                }
            }
        }
        return res
        
    }
