// Insertion
#include<iostream>
using namespace std;

class BST {
    int data;
    BST *left, *right;

    public:
        BST();
        BST(int);
        BST* Insert(BST*, int);
        void Inorder(BST*);
        bool Search(BST*, int);
        int FindMin(BST*);
        int FindMax(BST*);
};

// Default Constructor definition.
BST :: BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

BST ::BST(int value) {
    data = value;
    left = right = NULL;
}

BST* BST ::Insert(BST* root, int value) {
    if(!root) {
        return new BST(value);
    }

    if (value > root->data) {
        root->right = Insert(root->right, value);
    } else {
        root->left = Insert(root->left, value);
    }

    return root;
}

void BST ::Inorder(BST* root) {
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root-> data << endl;
    Inorder(root->right);
}

bool BST ::Search(BST* root, int value) {
    if(!root) return false;
    else if(root->data == value) return true;
    else if(value <= root->data) return Search(root->left, value);
    else return Search(root->right, value);    
}

int BST ::FindMin(BST* root) {
    if (!root) {
        cout << "Error: Tree is empty\n";
        return -1;
    }

    while(root->left) {
        root = root->left;
    }

    return root->data;
}

int BST ::FindMax(BST* root) {
    if (!root) {
        cout << "Error: Tree is empty\n";
        return -1;
    }

    while(root->right) {
        root = root->right;
    }

    return root->data;
}


int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
 
    b.Inorder(root);


    int number;
    cout << "Enter a number to search:\n";
    cin >> number;

    if(b.Search(root, number) == true) cout << "Found\n";
    else cout << "Not Found\n";

    cout << b.FindMax(root) <<"\n";
    cout << b.FindMin(root) <<"\n";

    return 0;
}