for i in xrange(input()):
    t = input()
    if sum(map(int,(raw_input().split()))) <= t:
        print("YES")
    else:
        print("NO")
