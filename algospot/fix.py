for t in range(int(input())):
    n = int(input())
    print(sum(i == t for i, t in enumerate(map(int, input().split()), 1)))
