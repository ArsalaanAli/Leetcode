class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        ans = self.Balanced(root)
        if ans == -1:
            return False
        else:
            return True
    def Balanced(self, root):
        #if leaf, return base case
        if root == None:
            return 0
        #get height left and right
        left = self.Balanced(root.left)
        right = self.Balanced(root.right)
        #if not balanced return -1
        if left == -1 or right == -1:
            return -1
        if abs(left-right) > 1:
            return -1
        #return max left right +1
        return max(left, right)+1
