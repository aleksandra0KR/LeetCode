struct Node{
    Node* prev = nullptr;
    Node* next = nullptr;
    int mic = 0;
    int val = 0;
    
    Node(int v){
        val = v;
    }

    Node(int v, Node* p){
        val = v;
        prev = p;
    }

};
class MinStack {
private:
    Node* head;
    int min_el;

public:
    MinStack() {
        head = nullptr;
        min_el = INT_MAX;
        
    }
    
    void push(int val) {
        if(!head){
            head = new Node(val);
            min_el = val;
            head->mic = val;
            return;
        }
        
        head = new Node(val, head);
        if(val < min_el){
            min_el = val;
        }

        head->mic = min_el;
        
    }
    
    void pop() {
        
        Node* temp = head;
        head = head->prev;
        if(head) min_el = head->mic;
        delete temp;
    }
    
    int top() {
        return head->val;
        
    }
    
    int getMin() {
        return head->mic;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */