for _ in xrange(input()):
    N, M, P = map(float, raw_input().split());
    r = 1.0 + P/1200.0;
    S = N * (r - 1.0) * r ** M / (r ** M - 1);
    print('%.8f' %S)

