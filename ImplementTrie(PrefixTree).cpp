class Node{
    public:
    char val;
    bool end = false;
    vector<Node*> next;
    Node(char v) : val(v), next(26, nullptr) {}
};

class Trie {
public:
    Node* head;
    Trie() {
        head = new Node('a');
    }
    
    void insert(string word) {
        Node* cur = head;
        for(char c : word){
            if(!cur->next[c-'a']){
                cur->next[c-'a'] = new Node(c);
            }
            cur = cur->next[c-'a'];            
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = head;
        for(char c : word){
            cur = cur->next[c-'a'];
            if(!cur){
                return false;
            }
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = head;
        for(char c : prefix){
            cur = cur->next[c-'a'];
            if(!cur){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */