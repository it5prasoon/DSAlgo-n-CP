#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int s,w1,w2,w3; cin>>s>>w1>>w2>>w3;
    if(s<=3){
        if((w1+w2<=s && w3<=s) || (w1<=s && w2+w3<=s)){
            if(w1+w2+w3<=s){
            cout<<"1";
        }
            else{
            cout<<"2";
        }
        }
        if(w1+w2>s && w2+w3>s){
            cout<<"3";
        }
    }
    else if(s==4 || s==5){
    if(w1+w2+w3<=s){
            cout<<"1";
        }
        else{
        cout<<"2";
        }
    }
    else if(s==6 || s==7 || s==8){
        cout<<"1";
    }
}


    return 0;
}