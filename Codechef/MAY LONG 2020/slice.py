t = int(input())
for i in range(t):
    n,m = map(int, input().split())
    array = list(map(int, input().split()))
    mod_arr=array


    for i in range(n):
        mod_arr = mod_arr[:n-i]
        print(mod_arr[i])

