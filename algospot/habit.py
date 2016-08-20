def getSuffixArray(s):
    n = len(s)
    group = [ord(i) for i in s]
    group.append(-1)
    perm = range(0, n)

    t = 1
    while t < n:
        compareUsing2T = lambda a, b: group[a] - group[b] if group[a] != group[b] else group[a+t] - group[b+t]
        perm.sort(cmp=compareUsing2T)
        if t*2 > n:
            break;
        newgroup = [-1]*(n+1)
        newgroup[perm[0]] = 0
        
        for i, j in zip(perm[0:], perm[1:]):
            nextgroup = 1 if compareUsing2T(i, j) else 0
            newgroup[j] = newgroup[i] + nextgroup
        group = newgroup
        t *= 2
    return perm
    
def commonPrefix(s, a, b):
    i = 0
    n = len(s)
    while i < n - max(a, b):
        if s[a+i] != s[b+i]:
            break;
        i += 1
    return i

def longestFrequent(k, s):
    sa = getSuffixArray(s)
    ret = 0
    for i in range(0, len(s) - k + 1):
        ret = max(ret, commonPrefix(s, sa[i], sa[i + k - 1]))
    return ret

for i in xrange(input()):
    k = input()
    s = raw_input()
    print(longestFrequent(k, s))    

