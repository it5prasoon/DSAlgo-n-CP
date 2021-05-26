#include<bits/stdc++.h>

using namespace std;


int main(){

int t; cin>>t;
while(t--){

    int n,m;
    cin>>n>>m;
    
  vector<vector<int> > v(2,vector<int> (n));
    for(int i=0;i<2;i++){
      for(int j=0;j<n;j++){
          cin>>v[i][j];
        }
       }
      vector<int> f;
      for(int i=0;i<n;i++){
        f.push_back(v[0][i]);
      }
int res = 1; 
  
    for (int i = 1; i < n; i++) { 
        int j = 0; 
        for (j = 0; j < i; j++) 
            if (f[i] == f[j]) 
                break; 
          if (i == j) 
            res++; 
    } 
    
  //  cout<<res<<" ";
 int ar[100000];
      for(int i=0;i<n;i++){
        int sum=v[1][i];
      if(v[0][i]!=0){
      for(int j=i+1;j<=n;j++){
          if(v[0][i]==v[0][j]){
                sum=sum+v[1][j];
                v[0][j]=0;
            }
    
        }
        ar[i]=sum;
        cout<<ar[i]<<" ";
      }
        
       }


   int min = ar[0];
for(int i=1;i<res;i++){
  if(ar[i]<min)
    min=ar[i];
    cout<<min<<" ";
}
cout<<min<<endl;

}

return 0;
}