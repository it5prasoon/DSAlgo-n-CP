// Insertion
#include<iostream>
#include<queue>
using namespace std;

class BTree {
    int data;
    BTree *left, *right;

    public:
        BTree();
        BTree(int);
        BTree* createBTree(BTree* root);
        BTree* Insert(BTree*, int);
        void Inorder(BTree*);
        bool Search(BTree*, int);
        int FindMin(BTree*);
        int FindMax(BTree*);
};

// Default Constructor definition.
BTree :: BTree()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

BTree ::BTree(int value) {
    data = value;
    left = right = NULL;
}

BTree* BTree ::Insert(BTree* root, int value) {
    if(!root) {
        return new BTree(value);
    }

    queue<BTree*> q;
    q.push(root);
 
    while (!q.empty()) {
        BTree* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = new BTree(value);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = new BTree(value);
            return root;
        }
    }

    return root;
}

void BTree ::Inorder(BTree* root) {
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root-> data << endl;
    Inorder(root->right);
}

BTree* BTree:: createBTree(BTree* root) {
    root = new BTree(10);
    root->left = new BTree(11);
    root->left->left = new BTree(7);
    root->right = new BTree(9);
    root->right->left = new BTree(15);
    root->right->right = new BTree(8);

    return root;
}

int main()
{
    BTree b, *root;

    root = b.createBTree(root);
    b.Inorder(root);

    cout << "==========================================\n";
    root = b.Insert(root, 12);
 
    b.Inorder(root);

    return 0;
}