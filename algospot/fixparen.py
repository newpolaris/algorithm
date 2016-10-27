for t in range(int(input())):
    s, open = input().split()
    s = list(s)
    dic = {'{': '}', '(': ')', '<': '>', '[': ']'}
    close = [dic[i] for i in open]
    stack = []
    for i, c in enumerate(s):
        if c in open:
            stack.append(i)
        else:
            io = stack.pop()
            o = s[io]
            idx = open.index(o)
            if idx > close.index(c):
                idx = close.index(c)
            s[io] = open[idx]
            s[i] = close[idx]
    print(''.join(s))
