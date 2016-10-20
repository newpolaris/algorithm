for t in range(int(input())):
    a, b = input().split()
    if a != b and sorted(a) == sorted(b):
        print("Yes")
    else:
        print("No.")
