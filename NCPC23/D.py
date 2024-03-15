t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    if a * d == b * c:
        print("Equal")
    else:
        print("Not Equal")