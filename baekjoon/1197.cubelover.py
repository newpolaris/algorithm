n,m=map(int,input().split())
p=list(range(n))
a=[[] for i in range(m)]
while m>0:
    m-=1
    i,j,k=map(int,input().split())
    a[m]=[k,j-1,i-1]
a.sort()
def par(x):
    if x==p[x]:
        return x
    p[x]=par(p[x])
    return p[x]
r=0
for i in a:
    if par(i[1])!=par(i[2]):
        r+=i[0]
        p[par(i[1])]=par(i[2])
print(r)
