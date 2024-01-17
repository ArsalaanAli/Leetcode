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
    int ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        treeSize(root, 0, k);
        return ans;
    }
    int treeSize(TreeNode* cur, int smallerParent, int k){
        if(ans>=0){
            return 0;
        }
        if(!cur){
            return 0;
        }
        int leftSize = treeSize(cur->left, smallerParent, k);
        if(leftSize+smallerParent+1 == k && ans<0){
            ans = cur->val;
            return 0;
        }
        if(ans>=0){
            return 0;
        }
        int rightSize = treeSize(cur->right, leftSize+1+smallerParent, k);
        return leftSize+rightSize+1;
    }
};
