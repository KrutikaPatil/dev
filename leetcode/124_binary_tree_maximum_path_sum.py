class Solution:
    def maxPathSum(self, root) -> int:
        if not root: return -2147483648
        if (not root.left) and (not root.right):
            return(root.val)
        temp_output = self.maxPathSum_helper(root)
        a=temp_output[0][1]
        b=temp_output[1][1]
        print(temp_output)
        max_ab = max(a,b)
        print(type(max_ab))
        print(max_ab)
        if max_ab == 0:
            max_val = self.max_value_in_tree(root)
            if max_val < 0:
                return max_val
        else:
                print(max_ab)
                return(max_ab)
            
            
        #print(max(a,b))
        #return(max(a,b))
    
    def max_value_in_tree(self,root):
        from collections import deque
        max_=-50000
        if not root: return 0
        q= deque([root])
        while len(q)>0:
            current = q.popleft()
            if current.val>max_:
                max_=current.val
            if current.left:
                    q.append(current.left)
            if current.right:
                    q.append(current.right)
        return max_        
            
    def maxPathSum_helper(self, root):
        if not root: 
            return([(1,0),(0,0)])
        elif (not root.left) and (not root.right):
            return([(1,root.val),(0,0)])
        else:
            left_subtree_sol = self.maxPathSum_helper(root.left)
            right_subtree_sol = self.maxPathSum_helper(root.right)
            s1 = right_subtree_sol[1][1]
            s3 = right_subtree_sol[0][1]
            s2 = left_subtree_sol[1][1]
            s4 = left_subtree_sol[0][1]
            case_0 = max(s1,s2,s3,s4)
            value = root.val
            case_1 = max(value, value+s3,value+s4,value+s3+s4)

            return([(1,case_1),(0,case_0)])


#
# [5,4,8,11,null,13,4,7,2,null,null,null,1]
# [-10,9,20,null,null,15,7]