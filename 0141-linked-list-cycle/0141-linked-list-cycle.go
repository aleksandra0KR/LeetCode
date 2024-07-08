/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type EmptyStruct struct{}
func hasCycle(head *ListNode) bool {
    
    i := head
    visited := make(map[*ListNode]EmptyStruct)
    
    for i != nil {
        if _, ok := visited[i]; ok {
            return true
        }
        visited[i] = EmptyStruct{}
        i = i.Next
    }
    
    return false
}