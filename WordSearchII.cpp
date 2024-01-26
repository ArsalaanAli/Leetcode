class Node{
    public:
    char val;
    bool end = false;
    int leadsTo = 0;
    vector<Node*> next;
    Node(char v) : val(v), next(26, nullptr) {}
};

class Solution {
public:
    set<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* head = new Node('a');
        insertWords(words, head);
        for(int y = 0; y<board.size(); y++){
            for(int x = 0; x<board[0].size(); x++){
                char check = board[y][x];
                if(head->next[check-'a']){
                    traverseBoard(board, head->next[check-'a'], "", y, x);
                }
            }
        }
        vector<string> ret(ans.begin(), ans.end());
        return ret;
    }
    int traverseBoard(vector<vector<char>>& board, Node* cur, string word, int y, int x){
        int completed = 0;
        word += board[y][x];
        if(cur->end){
            cur->end = false;
            ans.insert(word);
            completed++;
        }
        board[y][x] = '-';
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(vector<int> d : dirs){
            if(y+d[0]>=0 && y+d[0]<board.size() && x+d[1]>=0 && x+d[1]<board[0].size()){
                char check = board[y+d[0]][x+d[1]];
                if(check == '-'){
                    continue;
                }
                if(cur->next[check-'a'] && cur->next[check-'a']->leadsTo > 0){
                    completed += traverseBoard(board, cur->next[check-'a'], word, y+d[0], x+d[1]);
                }
            }
        }
        cur->leadsTo-=completed;
        board[y][x] = cur->val;
        return completed;
    }
    void insertWords(vector<string>& words, Node* head){
        for(string word : words){
            Node* cur = head;
            for(char c : word){
                if(!cur->next[c-'a']){
                    cur->next[c-'a'] = new Node(c);
                }
                cur = cur->next[c-'a'];
                cur->leadsTo++;
            }
            cur->end = true;
        }
    }
};