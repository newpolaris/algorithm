from operator import itemgetter

class Node(object):
    def __init__(self, x, y, r):
        self.x, self.y, self.r = x, y, r
        self.child = []

    def contain(self, n):
        return (self.x - n.x) ** 2 + (self.y - n.y) ** 2 < (self.r - n.r) ** 2;

    def addChild(self, n):
        for c in self.child:
            if c.contain(n):
                c.addChild(n)
                return
        self.child.append(n)
    
    def maxdist(self, m):
        if not self.child:
            return 0
        m1, m2 = 0, 0
        for i in self.child:
            m2 = max(m2, i.maxdist(m) + 1)
            if m2 > m1:
                m1, m2 = m2, m1
        global longest
        longest = max(longest, m1 + m2) 

        return m1

    def __repr__(self):
        return "[ x = {}, y = {}, r = {} ]".format(self.x, self.y, self.r)

for i in xrange(input()):
    n = input()
    inputs = [map(int, raw_input().split()) for _ in xrange(n)]
    inputs.sort(key=itemgetter(2), reverse=True)

    nodes = [Node(i[0], i[1], i[2]) for i in inputs]
    root = nodes.pop(0)
    for node in nodes:
        root.addChild(node)
    longest = 0
    root.maxdist(0)
    print(longest)

    
