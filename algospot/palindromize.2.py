# can't solve abba (4 vs 7), ab (3 vs 2)
t = [0]*9**6
def f(s):
    n = len(s)
    t[0] = 0
    # just like match. but some exceptions
    begin, m = 1, 0
    while begin + m < n:
        # not s[m] but s[-m-1]
        if s[begin+m] == s[-m-1]:
            m += 1
            # not t[begin+m-1]
            t[begin+m] = m
        elif m:
            begin += m - t[m]
            m = t[m]
        else:
            begin += 1
        l = t[n]
    # if n - 1 - l > 0: then l + 2 * (n - 1) else n
    print n - 1 - l and l + 2 * (n - l) or n

# loop n times with n input
exec"f(raw_input());"*input()
