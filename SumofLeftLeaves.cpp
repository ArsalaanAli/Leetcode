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
private:
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root, false);
        return sum;
    }
    void helper(TreeNode* root, bool left){
        if(!root){
            return;
        }
        if(!root->left && !root->right && left){
            sum+=root->val;
        }
        helper(root->left, true);
        helper(root->right, false);
    }
};
