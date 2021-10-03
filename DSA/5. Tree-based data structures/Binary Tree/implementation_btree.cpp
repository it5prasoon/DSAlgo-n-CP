// Insertion
#include<iostream>
#include<queue>
using namespace std;

class BTree {
    BTree *left, *right;

    public:
        int data;

        BTree();
        BTree(int);
        BTree* createBTree(BTree* root);
        BTree* Insert(BTree*, int);
        void Inorder(BTree*);
        int findMax(BTree *root);
        int findMin(BTree *root);
        int size(BTree *root);
        int height(BTree *root);
        BTree* deepestNode(BTree *root);
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

int BTree ::findMax(BTree* root) {
    int temp, left, right, max = INT32_MIN;
    if (!root) {
        return -1;
    }

    temp = root->data;
    left = findMax(root->left);
    right = findMax(root->right);

    if(left > right) {
        max = left;
    } else max = right;

    if(temp > max) {
        max = temp;
    }

    return max;
}

int BTree ::findMin(BTree* root) {
    int temp, left, right, min = INT32_MAX;
    if (!root) {
      return min;
    }

    temp = root->data;
    left = findMin(root->left);
    right = findMin(root->right);

    if(left < right) {
        min = left;
    } else min = right;

    if(temp < min) {
        min = temp;
    }

    return min;
}

int BTree ::size(BTree *root) {
    if (!root) {
        return 0;
    } else {
        return(size(root->left) + 1 + size(root->right));
    }
}

int BTree ::height(BTree *root) {
    int leftheight, rightheight;

    if (!root) {
        return 0;
    } else {
        leftheight = height(root->left);
        rightheight = height(root->right);

        if (leftheight > rightheight) 
            return leftheight+1;
        else
            return rightheight+1;
    }
}

BTree* BTree ::deepestNode(BTree *root) {
    BTree* temp = new BTree();
    queue<BTree*> q;

    if(!root) {
        return NULL;
    }

    q.push(root);

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    while(!q.empty()) {
        q.pop();
    }

    return temp;
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
    BTree b, *root, *deepnode;

    root = b.createBTree(root);
    b.Inorder(root);
    cout << "Size is: " << b.size(root) << endl;

    cout << "==========================================\n";
    root = b.Insert(root, 12);
    b.Inorder(root);

    cout << "Size is: " << b.size(root) << endl;
    cout << "Maximum number: " << b.findMax(root) << "\n";
    cout << "Minimum number: " << b.findMin(root) << "\n";
    cout << "Height: " << b.height(root) << "\n";

    deepnode = b.deepestNode(root);
    cout << "Deepest Node: " << deepnode->data;
    
    return 0;
}