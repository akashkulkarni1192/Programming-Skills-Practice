a=0
b=1

num = raw_input("Enter number")



L=[0,1,1]
def fib(n):
	return 0 if n==0
	return 1 if n==1
	
	ans=fib(n-1)+fib(n-2)
	
	L.append(ans) if ans not in L
	return ans

fib(int(num)-1)


print L
