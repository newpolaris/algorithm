import math
for t in xrange(input()):
    N, M = map(float, raw_input().split())
    R = 100*M//N + 1;
    X = -1
    if R < 100:
        X = math.ceil((R*N - 100*M)/(100-R)) 
    print(int(X))
