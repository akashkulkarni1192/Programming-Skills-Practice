input=[1,4,1,2,7,5,2]
output=[0 for i in range(len(input)+1)]

freq = [0 for i in range(max(input)+1)]

print freq

#print map(lambda i:freq[i]+1,input)
for i in input:
	freq[i]=freq[i]+1

print freq
count=[0]
for i in range(1,len(freq)):
	count.append(sum(freq[0:i+1]))
print count
for i in input:
	output[count[i]]=i
	count[i]=count[i]-1

print output
