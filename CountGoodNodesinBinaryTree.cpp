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
    int goodNodes(TreeNode* root) {
        return recurse(root, root->val);
    }
    int recurse(TreeNode* cur, int max){
        if(cur == NULL){
            return 0;
        }
        int ans = 0;
        if(cur->val >= max){
            ans = 1;
            max = cur->val;
        }
        return ans + recurse(cur->left, max) + recurse(cur->right, max);
    }
};

