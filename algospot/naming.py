# Kmp failure function 
a = raw_input()
b = raw_input()
a += b
m, n = 0, len(a)
pi = [0]*n
for i in range(1, n):
    while m > 0 and a[i] != a[m]:
        m = pi[m-1]
    if a[i] == a[m]:
        m += 1
    pi[i] = m 
l = []
k = n
while k > 0:
    l.append(k)
    k = pi[k - 1]
print(" ".join([str(i) for i in reversed(l)]))
