t = int(input())

while t > 0:
    n = int(input())

    arr = map(int, input().split())
    arr = list(arr)

    for i in range(n):
        if arr[i] not in arr[i+1:] and arr[i] not in arr[:i]:
            print(i+1)
            break
    t -= 1