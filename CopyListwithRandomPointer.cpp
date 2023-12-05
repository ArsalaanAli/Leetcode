class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* cur = head;
        while(cur){
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur){
            Node* copy = map[cur];
            copy->next = map[cur->next];            
            copy->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};


