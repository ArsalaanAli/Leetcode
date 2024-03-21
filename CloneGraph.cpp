/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, Node*> dict;
    set<int> visited;
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        Node* first = new Node(node->val);
        dict[node->val] = first;
        recurse(node, first);
        return first;
    }
    void recurse(Node* oNode, Node* copyNode){
        for(Node* n : oNode->neighbors){
            if(dict.count(n->val)){
                copyNode->neighbors.push_back(dict[n->val]);
            }
            else{
                Node* temp = new Node(n->val);
                dict[n->val] = temp;
                copyNode->neighbors.push_back(temp);
            }
        }
        visited.insert(oNode->val);
        for(Node* n : oNode->neighbors){
            if(!visited.count(n->val)){
                recurse(n, dict[n->val]);
            }
        }
    }
};