
def largestRectangleArea(heights):

    n = len(heights)
        if n==1: return (heights[0])
        if n==0: return (0)
        r = n
        l = r - 1
        A_max = 0
        h_current = heights[r-1]
        h_new = h_current
        while l > -1:
            print("l is %s : A_max is %s" %(str(l),str(A_max)))
            #print(A_max)
            
            if h_new <= h_current:
                A_current = (r - l) * h_new
                if A_current > A_max:
                    A_max = A_current
                h_current = heights[l]
                l = l - 1
                h_new = heights[l]
            else:
                A1 = (l + 1 - l) * h_new
                A2 = (r - l ) * h_current
                if A1 > A2 and A1 > A_max:
                    r = l+1
                    A_max = A1
                elif A2 > A1 and A2 > A_max:
                    A_max = A2
                h_current = heights[l]
                l = l - 1
                if l!= -1:
                    h_new = heights[l]
        return (A_max)
'''
n = len(heights)
        if n==1: return (heights[0])
        if n==0: return (0)
        r = n
        l = r - 1
        l_bucket=l
        A_max = 0
        h_current = heights[r-1]
        h_new = h_current
        h_min = h_new 
        while l > -1:
            
            #print(A_max)
            print("hnew ; h_current %d %d " %(h_new,h_current))
            print("l is %s : A_max is %s" %(str(l),str(A_max)))
            if h_new <= h_current:
                A_current = (r - l) * h_min
                print('hmin %d' %h_min)
                #A2 = ()
                if A_current > A_max:
                    A_max = A_current
                    l_bucket = l
                    
                h_current = heights[l]
                l = l - 1
                h_new = heights[l]
                if h_new < h_min : h_min = h_new
            else:
                
                A1 = (l + 1 - l) * h_new
                A2 = (r - l ) * h_current
                print('h_new>=h_current. A1, A2,  %d %d' %(A1,A2))
                if A1 >= A2 and A1 > A_max:
                    r = l+1
                    A_max = A1
                elif A2 >= A1 and A2 > A_max:
                    A_max = A2
                h_current = heights[l]
                l = l - 1
                if l!= -1:
                    h_new = heights[l]
                    if h_new < h_min : h_min = h_new
            
        return (A_max)
        



'''