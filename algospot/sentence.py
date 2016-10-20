m, n = map(int, input().split())
dic = {}
for i in range(m):
    line = input()
    for i in range(1, len(line)+1):
        dic[line[:i]] = 1
cnt = 0
for i in range(n):
    line = input()
    if line in dic:
        cnt += 1
print(cnt)
