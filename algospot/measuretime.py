import sys
import gc

input = sys.stdin.readline
k = 1000000

def sum(pos):
    pos += 1
    ret = 0
    while pos > 0:
        ret += arr[pos]
        pos &= (pos - 1)
    return ret

def add(pos, val):
    pos += 1
    while pos < len(arr):
        arr[pos] += val
        pos += pos & -pos
    
for c in xrange(int(input())):
    gc.collect()
    n = int(input())
    L = map(int, input().split())
    arr = [0]*(k+2)
    ret = 0
    for l in L:
        ret += sum(k) - sum(l)
        add(l, 1)
    print(ret)
