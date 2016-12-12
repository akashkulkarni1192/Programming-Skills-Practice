from collections import deque

L = deque(maxlen=3)

for i in range(5):
	L.append(i)
	print L
