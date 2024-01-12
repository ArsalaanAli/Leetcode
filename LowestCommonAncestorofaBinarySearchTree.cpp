//Did this 2 ways, first way was too complicated, slower, and took more memory. Second way was braindead easy...
//First way
/*
class Solution {
public:
    set<TreeNode*> nodeSet;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TraverseTree(root, p);
        cout<<"NEXT"<<endl;
        return TraverseTree(root, q);
    }
    TreeNode* TraverseTree(TreeNode* cur, TreeNode* target){
        if(nodeSet.count(cur)){
            if(cur==target){
                return cur;
            }
            TreeNode* result = (target->val > cur->val ? TraverseTree(cur->right, target) : TraverseTree(cur->left, target));
            if(result){
                return result;
            }
            return cur;
        }
        nodeSet.insert(cur);
        if(cur == target || cur == NULL){
            return NULL;
        }
        if(target->val > cur->val){
            return TraverseTree(cur->right, target);
        }
        else{
            return TraverseTree(cur->left, target);
        }

    }
};
*/

//Second way
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if p and q are both to left
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};