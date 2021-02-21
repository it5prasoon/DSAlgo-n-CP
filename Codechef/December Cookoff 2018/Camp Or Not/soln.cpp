#include <iostream>
using namespace std;

int main() {
	int T;
	int D;
    cin>>T;
	while(T--)
	{
	  cin>>D;
	  int a[32] ={0};
	  int d[32];
	  
	  for(int i=1;i<=D;i++)
	  {
	      int di;
	      int pi;
	      cin>>di;
	      cin>>pi;
	      a[di]=pi;
	  }
	  int q; cin>>q;int c;
	  c = 0;
	  for(int i=1;i<=32;i++)
	  {
	      c+=a[i];d[i]=c;
	  }
	  while(q--)
	  {
	    int di,pi;
	    cin>>di>>pi;
	    if(d[di]>=pi)
        cout<<"Go Camp\n";
        else
        cout<<"Go Sleep\n";
	      
	  }
	}
	return 0;
}
