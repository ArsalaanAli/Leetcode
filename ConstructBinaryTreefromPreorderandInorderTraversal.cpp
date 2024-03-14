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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        TreeNode* ans = recurse(start, 0, inorder.size()-1, preorder, inorder);
        return ans;
    }
    TreeNode* recurse(int& start, int l, int r, vector<int>& preorder, vector<int>& inorder){
        if(l > r){
            return nullptr;
        }
        int head;
        for(int j = l; j<=r; j++){
            if(preorder[start] == inorder[j]){
                head = j;
                break;
            }
        }
        start++;
        TreeNode* leftSub = recurse(start, l, head-1, preorder, inorder);
        TreeNode* rightSub = recurse(start, head+1, r, preorder, inorder);
        TreeNode* cur = new TreeNode(inorder[head], leftSub, rightSub);
        return cur;
    }
};

