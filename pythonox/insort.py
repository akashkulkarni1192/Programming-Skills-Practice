L=[6,5,4,3,2,1]

for i in range(1,len(L)):
	a=L[i]
	j=i-1
	while j>=0 and a<L[j]:
		print 
		L[j+1]=L[j]
		j=j-1
	L[j+1]=a

print L
