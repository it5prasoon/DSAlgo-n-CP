#include<bits/stdc++.h>

using namespace std;


int main(){

int l; cin>>l;
while(l--){

    int n,m;
    cin>>n>>m;
    
    vector<int> f;
    vector<int> p;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x;
        f.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>y;
        p.push_back(y);
    }

int ar[100000];
for(int i=0;i<n;i++){
    int sum=p[i];
    if(f[i]!=0){
        for(int j=i+1;j<n;j++){
            if(f[i]==f[j]){
                sum=sum+p[j];
                f[j]=0;
            }
        }
        ar[i]=sum;
    }
    else
    {
        ar[i]=100000;
    }
    
}


   int min = ar[0];
for(int i=1;i<n;i++){
  if(ar[i]<min)
    min=ar[i];
}
cout<<min<<endl;

}

return 0;
}