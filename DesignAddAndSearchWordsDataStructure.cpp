class Node{
    public:
    char val;
    Node* next[26];
    bool end = false;
    Node(char v){
        val = v;
        for(int i = 0; i<26; i++){
            next[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    Node* head;
    WordDictionary() {
        head = new Node('a');
    }
    
    void addWord(string word) {
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
        return recurse(word, head);
    }

    bool recurse(string word, Node* cur){
        for(int c = 0; c<word.size(); c++){
            if(word[c] == '.'){
                if(word.size() == 1 && c != word.size()-1){
                    return true;
                }
                string trunc = word.substr(c+1);
                for(Node* n : cur->next){
                    if(n && recurse(trunc, n)){
                        return true;
                    }
                }
                return false;
            }
            if(!cur->next[word[c]-'a']){
                return false;
            }
            else{
                cur = cur->next[word[c]-'a'];
            }
        }
        return cur->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */