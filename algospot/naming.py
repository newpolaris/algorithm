# Kmp failure function 
a = raw_input()
b = raw_input()
pattern = a + b
matched, n = 0, len(pattern)
pi = [0]*n
for i in range(1, n):
    while matched > 0 and pattern[i] != pattern[matched]:
        matched = pi[matched-1]
    if pattern[i] == pattern[matched]:
        matched += 1
    pi[i] = matched 
l = []
while n > 0:
    l.append(n)
    n = pi[n - 1]
print(" ".join([str(i) for i in reversed(l)]))
