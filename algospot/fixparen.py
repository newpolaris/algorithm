def correct(i, partial):
    if i >= len(s):
        return ''
    c = s[i]
    if c in open:
        stack.append(c)
        return correct(i+1, )
    else:
        o = stack.pop()
        idx = open.index(o)
        if idx > close.index(c):
            idx = close.index(c)
        return open[idx] + partial + close[idx]

for t in range(int(input())):
    s, open = input().split()
    s = list(s)
    dic = {'{': '}', '(': ')', '<': '>', '[': ']'}
    close = [dic[i] for i in open]
    stack = []
    ans = ''
    temp = ''
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
