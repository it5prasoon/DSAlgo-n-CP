t = int(input())

for i in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    l.sort()
    if sum(l[:n]) == l[n-2]:
        ans = " ".join(l[:n])
    elif sum(l[:n]) == l[n-1]:
        ans = " ".join(l[:n])
    else:
        ans = -1
    print(ans)