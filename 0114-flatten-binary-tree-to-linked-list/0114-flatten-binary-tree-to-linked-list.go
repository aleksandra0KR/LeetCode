/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */func returnNode(root *TreeNode, res *[]int) {
        if root == nil{
            return
        }
        if root.Left != nil {
            *res = append(*res, root.Left.Val)
            returnNode(root.Left, res)
        }
        if root.Right != nil {
            *res = append(*res,root.Right.Val)
            returnNode(root.Right, res)
        }

    }

func flatten(root *TreeNode) {
        res := *new([]int)
        returnNode(root, &res)
        
        for _, a:= range res{
            root.Right = &(TreeNode{a, nil, nil})
            root.Left = nil
            root = root.Right
        }
}