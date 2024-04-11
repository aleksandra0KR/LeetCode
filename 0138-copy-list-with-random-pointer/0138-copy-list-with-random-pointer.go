/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    
     if head == nil {
        return nil
    }

    var replacement map[*Node]*Node = make(map[*Node]*Node)
   
    var curent *Node  = head
    for curent != nil {
        replacement[curent] = &Node{ Val:curent.Val }
        curent = curent.Next
    }
    
    curent = head
    var newNode *Node
    for curent != nil {
        newNode = replacement[curent]
        newNode.Next = replacement[curent.Next]
        newNode.Random = replacement[curent.Random]
        curent = curent.Next
    }
    
    return replacement[head]

}