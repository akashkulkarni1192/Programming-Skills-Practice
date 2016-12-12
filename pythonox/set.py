L1,L2=['a','b','c',2,3],[1,2,3,'a','b']

#union

uni = set(L1)|set(L2)
print 'union : ',uni

inter = set(L1)&set(L2)
print 'intersection : ',inter

cart = [(x,y) for x in L1 for y in L2]
print 'cartesian product : ',cart


