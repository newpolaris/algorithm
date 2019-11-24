# yoshiko's
q = []
def a(t):
	if len(q): exec('print(' + t)
	else : print(-1)
for i in range(int(input())):
	t = input()
	p = t[1]
	if p == 'u': q += [t.split()[1]]
	elif p == 'o': a('q.pop(0))')
	elif p == 'i': print(len(q))
	elif p == 'm': print((len(q) == 0)* 1)
	elif p == 'r': a('q[0])')
	else: a('q[-1])')

# zinc
s,p=[],print
input()
while 1:
 try:c=input().split()
 except:break
 d,e=c[0][:2],not s
 if'pu'==d:s.append(c[1])
 if'po'==d:p(-1 if e else s.pop(0))
 if'si'==d:p(len(s))
 if'em'==d:p(int(len(s)==0))
 if'fr'==d:p(-1 if e else s[0])
 if'ba'==d:p(-1 if e else s[-1])
