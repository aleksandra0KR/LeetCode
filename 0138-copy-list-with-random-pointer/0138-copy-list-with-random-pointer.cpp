/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
   unordered_map<Node*, Node*> replacement;
    
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        if(replacement.find(head) != replacement.end()) return replacement[head];
        
        Node* newNode = new Node(head->val);
        
        replacement[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        
        return replacement[head];
    }
};