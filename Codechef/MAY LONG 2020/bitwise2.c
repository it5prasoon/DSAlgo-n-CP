#include<stdio.h>

int main()
{
    int t; scanf("%d",&t);
    while(t--){
        int x,y,l,r,i,ans; scanf("%d %d %d %d ",&x,&y,&l,&r);
        int max = -1;
        for(i=l; i<r+1; i++){
            int temp = (x&i)*(y&i);
            if(temp>max){
                max=temp;
                ans = i;
            }
        }
        printf("%d",ans)
    }
    return 0;
}