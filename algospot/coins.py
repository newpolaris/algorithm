for i in xrange(input()):
    M, C = map(int, raw_input().split())
    coins = list(map(int, raw_input().split()))
    cache = [0] * (M+1)
    cache[0] = 1
    for c in coins:
        for i in range(0, M-c+1):
            cache[c+i] += cache[i];
    print cache[M] % 1000000007;
