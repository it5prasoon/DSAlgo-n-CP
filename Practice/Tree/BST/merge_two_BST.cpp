// Not fully solved

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

class snode
{
    public:
    Node *t;
    snode *next;
};
 
void push(snode **s, Node *k)
{
    snode *tmp = new snode();
 
    tmp->t = k;
    tmp->next = *s;
    (*s) = tmp;
}
 
// Function to pop an element t from stack
Node *pop(snode **s)
{
    Node *t;
    snode *st;
    st=*s;
    (*s) = (*s)->next;
    t = st->t;
    free(st);
    return t;
}

int isEmpty(snode *s)
{
    if (s == NULL )
        return 1;
 
    return 0;
}


class Solution
{
    public:
    vector<int> inorder(Node *root) {
        vector<int> in;
        if (root != NULL){
            inorder(root->left);
            in.push_back(root->data);
            inorder(root->right);
        }
        return in;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
        vector<int> solution;

        if (root1 == NULL){
            solution = inorder(root2);
            return solution;
        }
        if (root2 == NULL) {
            solution = inorder(root1);
            return solution;
        }

        snode *s1 = NULL;
        snode *s2 = NULL;

        Node *curr1 = root1;
        Node *curr2 = root2;


        while (curr1 != NULL || !isEmpty(s1) ||
             curr2 != NULL || !isEmpty(s2)) {
                 
            if (curr1 != NULL || curr2 != NULL ) {
                if (curr1 != NULL) {
                    push(&s1, curr1);
                    curr1 = curr1->left;
                }

                if (curr2 != NULL) {
                    push(&s2, curr2);
                    curr2 = curr2->left;
                }
            } else {
                if (isEmpty(s1)) {
                    while (!isEmpty(s2)) {
                        curr2 = pop(&s2);
                        curr2->left = NULL;
                        solution = inorder(curr2);
                    }

                    return solution;
                }
                if (isEmpty(s2)) {
                    while (!isEmpty(s1)) {
                        curr1 = pop(&s1);
                        curr1->left = NULL;
                        solution = inorder(curr1);
                    }
                    return solution;
                }

                curr1 = pop(&s1);
                curr2 = pop(&s2);


                if (curr1->data < curr2->data) {
                    cout << curr1->data<<" ";
                    curr1 = curr1->right;
                    push(&s2, curr2);
                    curr2 = NULL;
                } else {
                    cout << curr2->data << " ";
                    curr2 = curr2->right;
                    push(&s1, curr1);
                    curr1 = NULL;
                }
            }
        }
        return solution;
    }
};

int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
} 