#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;
public:

    void enqueue(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
 
        s1.push(x);
 
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if (s1.empty()) {
            cout << "Empty queue!";
            exit(0);
        }
 
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}
