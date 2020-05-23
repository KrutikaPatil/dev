def minDistance( word1,  word2):
    
    # base cases of recursion
    if (word1,word2) in dict_.keys():
        #print("found in dictionary %s, %s" %(word1, word2))
        #print(dict_)
        return dict_[(word1,word2)]
    #print (dict_)
    #print("function call with %s, %s" %(word1, word2))
    if word1 == word2 :
        #rint("case1")
        k =0
        #print("    answer for this call %s" % (str(k)))
        dict_[(word1,word2)] = k
        return k  
    elif len(word1) == 1 and len(word2) == 1 :
        #print("case2")
        k=1
        #print("    answer for this call %s" % (str(k)))
        dict_[(word1,word2)] = k
        return k
    elif len(word1)==0:
        k = len(word2)
        dict_[(word1,word2)] = k
        return k
    elif len(word2) == 0:
        k = len(word1)
        dict_[(word1,word2)] = k
        return k
    elif word1[0] == word2[0]:
        k = minDistance(word1[1:], word2[1:])
        dict_[(word1,word2)] = k
        return k
    else:
        #print("case 5")
        # insertion case
        #word1 = word2[0] + word1
        subproblem_solution1 = 1 + minDistance(word1, word2[1:]) # -- 1+(k,ke)
        # deletion case
        #word1 = word1[1:]
        subproblem_solution2 = 1 + minDistance(word1[1:], word2)# -- 1+ (0,ake)
        # replacement case
        #word1[0] = word2[0]
        subproblem_solution3 = 1 + minDistance(word1[1:], word2[1:]) #-- 1+(0,ke)
        #print(subproblem_solution1)
        #print(subproblem_solution2)
        #print(subproblem_solution3)
        k = min(subproblem_solution1, subproblem_solution2, subproblem_solution3)
        dict_[(word1,word2)] = k
        #print("    answer for this call %s" % (str(k)))
        return k

#k, ake
#- ak, ake -- 
#- , ake --
#- a,ake --



dict_={}
worda = "dinitrophenylhydrazine"
wordb = "benzalphenylhydrazone"





''' 
#print("Final Solution")

insertion :- cdb  _______  1 + (db, a)
       1 + 2

deletion :- 1 + (b, ca)
            1+ 
replacement :- (b, a)
            1 + 1
'''
ans = minDistance(worda, wordb)
print("Final answer")
print(ans)

'''
Edit distance possible choices: insert, delete, replace
Output: Minimum number of operations required

cat --> call
cat --> dog


dcat dog
    cat og
    ocat og
        cat g
        gcat g



iterate over string 1:
    chars are same or different:
        if same move to next 
        else :
            try all three
                insert d before string 1 and recurse
                delete c from string 1 and recurse
                replace c to d and recurse

Dynamic programming principles:
    - breakdown into smaller subproblems, recursively solve them or iterate
    - memoization like in knapsack
    - 
'''