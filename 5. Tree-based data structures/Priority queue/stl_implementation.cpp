#include<bits/stdc++.h>
using namespace std;

void addElement(priority_queue<int> &A,int x);
void remove_Element(priority_queue<int> &A);
int getSize(priority_queue<int> &A);
int getElement_at_top(priority_queue<int> &A);
void print(priority_queue<int> &A);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        priority_queue<int> A;
        while(q--)
        {
            int c;
            cin>>c;
            switch(c)
            {
            case 1:{
                int x;
                cin>>x;
                addElement(A,x);
                print(A);
                break;
            }
            case 2:
                {
                    remove_Element(A);
                    break;
                }
            case 3:
                {
                    cout<<getElement_at_top(A)<<endl;
                    break;
                }
            case 4:
                {
                    cout<<getSize(A)<<endl;
                    break;
                }
            case 5:
                {
                    print(A);
                    break;
                }
            default: return 0;
            }
        }
    }
    return 0;
}

void addElement(priority_queue<int> & A, int x)
{
    A.push(x);
}

void remove_Element(priority_queue<int> &A)
{
    cout << A.top() << "\n";
    A.pop();
}

int getElement_at_top(priority_queue<int> &A)
{
    return A.top();
}

int getSize(priority_queue<int> &A)
{
    return A.size();
}

void print(priority_queue<int> &A)
{
    priority_queue<int> a;
    a = A;
    if (A.empty()) {
        cout << "-1" << endl;
        return;
    }
    int size = getSize(A);
    for (int i=0; i<size; i++) {
        cout << A.top() << " ";
        A.pop();
    }

    A=a;
    cout << endl;
}



