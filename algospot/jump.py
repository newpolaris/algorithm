for c in range(int(input())):
    n = int(input())+1
    k = sum(range(n))+1
    print((sum(range(k))*2 + k) % 20130728)
