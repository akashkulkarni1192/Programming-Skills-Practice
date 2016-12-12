import re
input = raw_input("Enter String :")
initial=input[:7]
codes = []
def calc_offset(p,b):
	i=b-1
	off=0
	while i>=p:
		if input[i]==input[b]:
			off=b-i
		i=i-1
	return off

def calc_length(off,b):
	if off==0:
		return 0,b+1
	l=0
	while input[b]==input[b-off]:
		b=b+1
		l=l+1
		if b>=len(input):
			break
	return l,b

def encode():
	print "\n\tEncoding ...\n"
	buf=7
	ptr=0
	length=0
	while buf<len(input):
		
		offset=0
		#print "present char = %s" % (input[buf])
		print '|'+input[ptr:buf]+'|'+'\t|'+input[buf:buf+6]+'|'
		offset=calc_offset(ptr,buf)
		length,buf=calc_length(offset,buf)
		if buf>=len(input):
			break
		if offset==0:
			code = (offset,length,'C('+input[buf-1]+')')
			print offset,length,input[buf-1]
			ptr=ptr+1
		else:
			code = (offset,length,'C('+input[buf]+')')
			print offset,length,input[buf]
			ptr=ptr+length+1
			buf=ptr+7
		codes.append(code)
		

		
def decode():
	print "\n\n\tDecoding ... :\n"
	output = initial
	ptr = len(initial)
	print output
	for triple in codes:
		i=len(output)-triple[0]
		j=1
		while j<=triple[1] :
			output = output+ output[i]
			i,j=i+1,j+1
		output = output + re.findall(r'[a-z]',triple[2])[0]
		print output
	print "\n\n\n"

encode()

print codes
decode()
