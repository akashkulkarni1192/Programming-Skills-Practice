L=['a','b','c','d']

def permutate(P,i):
	if i==len(P):
		print P
		
	else:
		for j in range(i,len(P)):
			P[i],P[j]=P[j],P[i]
			permutate(P,i+1)
			P[i],P[j]=P[j],P[i]


permutate(L,0)
