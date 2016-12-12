2=[L,1,3,-44,5,6,-1,2,120,-1]
maxx=0
start=end=0
for left in range(0,len(L)):
	for right in range(left,len(L)):
		summ=0
		for i in range(left,right+1):
			summ=summ+L[i]
		if maxx<summ:
			maxx=summ
			start=left
			end=right

print L[start:end+1]
