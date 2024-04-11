/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    
    Map<Node, Node> replacement = new LinkedHashMap<Node, Node>();
    
    public Node copyRandomList(Node head) {
        
        if(head == null) return null;
        
        if(replacement.containsKey(head)) return replacement.get(head);
        
        Node newNode = new Node(head.val);
        
        replacement.put(head, newNode);
        newNode.next = copyRandomList(head.next);
        newNode.random = copyRandomList(head.random);
        
        return replacement.get(head);
    }  
        
}