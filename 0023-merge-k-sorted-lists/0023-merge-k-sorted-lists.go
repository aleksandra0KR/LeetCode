/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */


func mergeKLists(lists []*ListNode) *ListNode {
    array := make ([]int, 0, 500 * 10000)
    
    for i := 0; i < len(lists); i++ {
        j := lists[i]
        for j != nil  {
            array = append(array, j.Val)
            j = j.Next
        }
    }
    
    if len(array) == 0 {
        return nil
    }
    
    sort.Ints(array)
    
    var result *ListNode
    var node *ListNode
    
    for _, a := range array {
        if result == nil {
            result =  &ListNode{a, nil}
            node = result
        } else {
            result.Next =  &ListNode{a, nil}
            result =  result.Next
        }
    }
    return node
}