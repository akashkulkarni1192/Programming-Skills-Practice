import sys
f = open("sample.txt")
line = f.readline()
w = open("output.txt","w")
while line:
	print line,
	print >>w, "%25s	%5s" % (line,"written")
	w.write("It\t Was nice Wrting %s"  % (line))
	line=f.readline()

f.close()
w.close()

print "Data Directly printed here"
print open("output.txt")
for line in open("output.txt"): print line ,

print >> sys.stdout,"Next ->\n"

sys.stdout.write("Enter Name:")
name = sys.stdin.readline()

print "Other way"
surname = raw_input("Enter surname:")


sys.stdout.write("%s%s"%(name,surname)) 


