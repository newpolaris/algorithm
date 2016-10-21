for t in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    print(sum(t+1 == l[t] for t in range(len(l))))
