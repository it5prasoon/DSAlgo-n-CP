#include<bits/stdc++.h>

using namespace std;

#include <iostream> 
using namespace std; 

struct Point 
{ 
	int x; 
	int y; 
}; 
 
bool onSegment(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	return true; 

	return false; 
} 
 
int orientation(Point p, Point q, Point r) 
{ 

	int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0; 

	return (val > 0)? 1: 2; 
} 

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	// General case 
	if (o1 != o2 && o3 != o4) 
		return true; 

	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false; 
} 


int main(){
    int t; 
    scanf("%d",&t);
    while(t--){
        int n,q; 
        scanf("%d",&n);
        scanf("%d",&q);
        int a[100000];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        
    while(q--){
        int x1,x2,y;
        scanf("%d",&x1);
        scanf("%d",&x2);
        scanf("%d",&y);
        int c=0;
        struct Point p2={x1,y},q2={x2,y};
        int c1=0,c2=0;
        for(int i=0;i<n-1;i++)
        {
            int k=a[i],l=a[i+1];
            struct Point p1={i+1,k}, q1={i+2,l};
            int t=doIntersect(p1,q1,p2,q2);
            
            if((p1.x==q2.x && p1.y==q2.y) || (q1.x==p2.x && q1.y==p2.y)){
                continue;
            }
            else{
                if(t==1)
                c++;
            }
       }
       
       printf("%d\n",c);
      
       
    }
    }
    return 0;
}