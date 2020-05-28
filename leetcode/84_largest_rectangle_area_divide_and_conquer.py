
def largestRectangleArea(heights):
    solution_candidates = _largestRectangleArea(heights)
    print('solution candidates')
    print(solution_candidates)
    sol1 = solution_candidates[0][0] *  solution_candidates[0][1]
    sol2 = solution_candidates[1][0] *  solution_candidates[1][1]
    sol3 = solution_candidates[2][0] *  solution_candidates[2][1]
    return max(sol1, sol2, sol3)
    
def _largestRectangleArea( heights):
        if len(heights) == 0:
            return ([(0,0),(0,0),(0,0)])
        elif len(heights) == 1:
            return ( [  (heights[0],1) ,(heights[0],1), (heights[0],1) ]   )
        else:
            mid = len(heights)/2
            left_array = heights[:mid]
            right_array = heights[mid:]
            left_solution = _largestRectangleArea(left_array)
            right_solution = _largestRectangleArea(right_array)
            if left_solution !=  [(0,0),(0,0),(0,0)]:
                a = left_solution[0]
                b = left_solution[1]
                c = left_solution[2]
            else:
                b=(0,0); c = (0,0); a=(0,0)
            
            if right_solution != [(0,0),(0,0),(0,0)]:
                d = right_solution[0]
                e = right_solution[1]
                f = right_solution[2]
            else:
                d=(0,0); e = (0,0); f=(0,0)
            h1 = c[0]
            h2 = d[0]
            l1 = c[1]
            l2 = d[1]
            f_cd = min(h1,h2)*( l1 + l2 )
            max_ = max(b[0]*b[1], e[0]*e[1], f_cd)
            if max_ == b[0]*b[1]:
                max_sol =b
            elif max_ == e[0]*e[1]:
                max_sol = e
            else:
                max_sol = (min(h1,h2),( l1 + l2 ))
            if len(left_array)==1:
                max_ = max(a[0]*a[1],f_cd)
                if max_ == a[0]*a[1]: a_=a
                elif max_==f_cd: a_=(min(h1,h2),( l1 + l2 ))
            else: a_=a
            if len(right_array)==1:
                max_ = max(f[0]*f[1],f_cd)
                if max_ == f[0]*f[1]: f_=f
                elif max_==f_cd: f_=(min(h1,h2),( l1 + l2 ))
            else: f_=f
            return(a_,max_sol,f_)
                


#heights1=[2,1,5,6,2,1]
heights1=[3,4]
print(largestRectangleArea(heights1))

# [4,2,0,3,2,4,3,4]
# [4,2,0,3]
# ((4, 1), (4, 1), (3, 1))

# [2,4,3,4]
# ((2, 2), (3, 3), (3, 2))


# [2,4]: ((2, 2), (4, 1), (4, 1))
# 















