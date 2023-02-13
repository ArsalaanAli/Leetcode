/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    set<int> stored;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        stored.insert(root->val);
        if(stored.count(k-root->val) && (k-root->val) != (root->val)){
            return true;
        }
        if(findTarget(root->right, k)){
            return true;
        }
        else if(findTarget(root->left, k)){
            return true;
        }
        return false;
        
    }
};