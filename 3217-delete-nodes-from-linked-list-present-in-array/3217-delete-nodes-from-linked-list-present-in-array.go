/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func modifiedList(nums []int, head *ListNode) *ListNode {
    numsMap := make(map[int]struct{})
    var headResult *ListNode
    for i := 0; i < len(nums); i++ {
        numsMap[nums[i]] = struct{}{}
    }
    node := head
    var result *ListNode
    for node != nil {
        if _, ok := numsMap[node.Val]; !ok {
            if headResult == nil {
                headResultnode := ListNode{node.Val, nil}
                headResult =  &headResultnode
                result = headResult
            } else {
                headResultnode := ListNode{node.Val, nil}
                headResult.Next =  &headResultnode
                headResult = headResult.Next
            }
            
        }
        node = node.Next
    }
    return result
}