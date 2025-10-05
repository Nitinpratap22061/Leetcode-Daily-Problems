# Last updated: 10/5/2025, 8:58:41 AM
class Solution:
    def __init__(self):
        self.res = 0

    def height(self, root):
        if not root:
            return 0

        left = self.height(root.left)
        right = self.height(root.right)

        self.res = max(self.res, left + right)

        return 1 + max(left, right)

    def diameterOfBinaryTree(self, root):
        self.height(root)
        return self.res

