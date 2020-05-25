from collections import deque
class Node():
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None




def serialise(root):
    """Encodes a tree to a single string.
        
    :type root: TreeNode
    :rtype: str
    """
    output_str = []
    q = deque([])    
    q.append(root)
    while len(q)>0:
        current = q.popleft()
        if current:
            output_str.append(current.val)
            q.append(current.left)
            q.append(current.right)
        else:
            output_str.append(None)
            q.append(None)
            q.append(None)
    return output_str





def deserialise(list_):

    return None


'''
Need a uniq representation of a binary tree
DFS, BFS, level order, in order, preorder, post order

'''


r = Node(1)
c1 = Node(2)
c2 = Node(3)
r.left=c1
r.right=c2
c3=Node(4)
c4=Node(5)

c2.left=c3
c2.right=c4

print(serialise(r))
