for i in range(int(input())):
    n=int(input())
    if n<=4:
        print(1)
        print(n,end=" ")
        for i in range(n):
            print(i+1,end=" ")
    else:
        j=4
        print(n//2)
        print(3,1,2,3)
        while j<n:
            if n-j>=1:
                print(2,j,j+1)
                j+=2
        if n%2==0:
            print(1,n)