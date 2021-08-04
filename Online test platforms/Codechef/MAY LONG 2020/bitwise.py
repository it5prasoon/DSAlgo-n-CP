t =int(input())
while t:
    x, y, l , r = map(int, input().split())
    max = -1
    for num in range(l, r+1):
        temp = (x & num)*(y & num)
#        print(temp, num)
        if temp> max:
            max = temp
            ans = num
    print(ans)

    t-=1