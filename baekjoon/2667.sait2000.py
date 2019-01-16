r,d,*a=0,{(x,y)for y in range(int(input()))for x,c in enumerate(input())if'0'<c}
while d:
 s=[d.pop()];r+=1;b=0
 while s:
  x,y=s.pop();b+=1
  for e in-2,0,2,4:
   p=x+e//3,y+e%3-1
   if{p}<=d:d-={p};s+=p,
 a+=b,
print(*[r]+sorted(a))
