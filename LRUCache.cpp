class Node{
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> map;
    Node* head = NULL;
    Node* tail = NULL;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(map.count(key)){
            useNode(map[key]);
            return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            map[key]->val = value;
            useNode(map[key]);
        }
        else{
            Node* temp = new Node(key, value);
            map[key] = temp;
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
            if(map.size() > cap){
                evictNode();
            }
        }
    }
    void useNode(Node* node){
        if(tail == node){
            return;
        }
        else if (head == node){
            head->next->prev = NULL;
            head = head->next;
            tail->next = node;
            node->prev = tail;
            node->next = NULL;
            tail = node;
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = tail;
            node->next = NULL;
            tail->next = node;
            tail = node;
        }
    }
    void evictNode(){
        if(head == NULL){
            return;
        }
        int hkey = head->key;
        head = head->next;
        if(head){
            head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        map.erase(hkey);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */