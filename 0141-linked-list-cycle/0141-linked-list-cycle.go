/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */


func hasCycle(head *ListNode) bool {
    
    if head == nil || head.Next == nil {
        return false
    }
    slow := head
    fast := head.Next
    
    for slow != fast && fast.Next != nil && fast.Next.Next != nil{
        slow = slow.Next
        fast = fast.Next.Next
    }
    
    if slow == fast {
        return true
    }
    
    return false
}