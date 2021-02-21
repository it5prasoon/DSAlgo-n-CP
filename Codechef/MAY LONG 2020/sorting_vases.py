t =int(input())
for _ in range(t):
    n,m = map(int, input().split())
    p = list(map(int, input().split()))
    robot_swaps = []
    for i in range(m):
        x,y = map(int, input().split())
        robot_swaps.append((x,y))
        robot_swaps.append((y,x))
    minute = 0
    minute_rev = 0
    p_ar=p



    if m==0:
        for i in range(n):
            p_ar = p_ar[:n-i]
            # print(p_ar[i])
            maximum_indices = p_ar.index(max(p_ar))
            if (p_ar[maximum_indices]!=p_ar[-1]):
                p_ar[maximum_indices], p_ar[-1] = p_ar[-1], p_ar[maximum_indices]
                minute+=1
        print(minute)


    else:
        for i in range(n):
            p_ar = p_ar[:n-i]
            maximum_indices = p_ar.index(max(p_ar))
            if (p_ar[maximum_indices]!=p_ar[-1]):
                p_ar[maximum_indices], p_ar[-1] = p_ar[-1], p_ar[maximum_indices]
                if (p_ar[maximum_indices], p_ar[-1]) not in robot_swaps:
                    minute+=1
        p_ar = p
        for i in range(n):
            manimum_indices = p_ar.index(min(p_ar[i:n]))
            if (p_ar[manimum_indices]!=p_ar[i]):
                p_ar[manimum_indices], p_ar[i] = p_ar[i], p_ar[manimum_indices]
                if (p_ar[manimum_indices], p_ar[i]) not in robot_swaps:
                    minute_rev+=1
        print(min([minute, minute_rev]))