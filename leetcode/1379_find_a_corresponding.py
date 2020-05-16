from collections import deque

# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        # Tree traversal options: 1) BFS 2) DFS 
        # Also inorder preorder postorder level order
        # What are the trade offs between all these traversal methods
        # BFS is level order traversal O(n)
        # DFS is inorder traversal also O(n)
        # Need to understand pre and post order traversal
        # Lets do BFS: queue
        q2 = deque([])
        q2.append(cloned)
        while len(q2)>0:
            c2=q2.popleft()
            if c2:
                if (c2.val==target.val):
                    return c2
                else:
                    q2.append(c2.left)
                    q2.append(c2.right)

        return None
