# l10veu's source
for c in xrange(input()):
    n, k = map(int, raw_input().split())
    a = [0, 1]
    for i in range(2, n):
        a = [(j+k-1)%i+1 for j in a]
    a.sort()
    print a[0]+1, a[1]+1

# dggon's source
# for _ in'*'*input():
#     N,K=map(int,raw_input().split())
#         P=range(1,N+1)
#         C=0
#         while len(P)>2:
#             P.pop(C)
#                 C=(C+K-1)%len(P)
#         print P[0],P[1]
