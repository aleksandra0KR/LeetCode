/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    
    i := head
  
    visited := make(map [*ListNode]bool)
    for i != nil {
        if ok, _ := visited[i]; ok {
            return true
        }
        visited[i] = true
        i = i.Next
    }
    return false
}