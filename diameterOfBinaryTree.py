# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    longestPath = 0
    def diam(self, root):
        if root == None:
            return 0
        leftPath = self.diam(root.left)
        rightPath = self.diam(root.right)
        self.longestPath = max(leftPath+rightPath, self.longestPath)
        return max(leftPath+1, rightPath+1)
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diam(root)
        return self.longestPath
    

