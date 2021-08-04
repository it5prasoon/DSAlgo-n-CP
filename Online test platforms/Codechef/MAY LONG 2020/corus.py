# Solution

t = int(input())

while t:
    n, q = map(int, input().split())
    str = input()

    lis = {}
    diff = 0
    for c in str:
        if c in lis:
            lis[c]+=1
        else:
            lis[c] = 1
            diff +=1
    while q:
        c = int(input())
        if c==0:
            print(n)
        elif c==1:
            print(n-diff)
        
        else:
            ans = sorted(lis.items(), key = lambda x: x[1])
            if ans[-1][1] <=c:
                print(0)
            else:
                counter = 0
                for ele in ans[::-1]:
                    if ele[1] >c:
                        counter += ele[1] - c
                    else:
                        break
                print(counter)
        q-=1
    t-=1