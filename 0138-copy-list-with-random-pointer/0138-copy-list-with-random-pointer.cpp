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
    
    void copyNode(Node* &head, Node* &tail, int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
       
    }
    
    Node* copyRandomList(Node* head) {
        Node* copyHead = NULL;
        Node* copyTail = NULL;
        Node* current = head;
        
        while(current != NULL){
            copyNode(copyHead, copyTail, current->val);
            current = current->next;
        }
        
        unordered_map<Node*, Node*> replacement;
        
        current = head;
        Node* currentCopy = copyHead;
        while(current != NULL){
            replacement[current] = currentCopy;
            current = current -> next;
            currentCopy = currentCopy->next;
        }
        
        currentCopy = copyHead;
        while(head != NULL){
            currentCopy->random = replacement[head->random];
            head = head->next;
            currentCopy = currentCopy->next;
        }
        
        return copyHead;
        
    }
};