def correct(l):
    if not l:
        return '', ''
    c = l.pop(0)
    if c in close:
        return c, l
    else:
        mid, post = correct(l)
        idx = min(open.index(c), close.index(mid[-1]))
        mid = mid[:-1] + close[idx]
        m, p = correct(post)
        return open[idx] + mid + m, p

for t in range(int(input())):
    s, open = input().split()
    s = list(s)
    n = len(s)
    dic = {'{': '}', '(': ')', '<': '>', '[': ']'}
    close = [dic[i] for i in open]
    print(correct(s)[0])
