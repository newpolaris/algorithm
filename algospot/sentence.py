M, N = map(int, input().split())
index = '\n'.join(input() for _ in range(M))
print(sum(input() in index for _ in range(N)))
