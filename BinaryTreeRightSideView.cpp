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
    vector<int> view;
    vector<int> rightSideView(TreeNode* root) {
        recurse(root, 1);
        return view;
    }
    void recurse(TreeNode* cur, int level){
        if(!cur){
            return;
        }
        if(view.size()<level){
            view.push_back(cur->val);
        }
        recurse(cur->right, level+1);
        recurse(cur->left, level+1);
    }
};

