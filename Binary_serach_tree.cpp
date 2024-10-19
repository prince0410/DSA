#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int value)
{

    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node *search(Node *root, int key)
{

    if (root == nullptr || root->data == key)
    {
        return root;
    }

    if (key > root->data)
    {
        return search(root->right, key);
    }

    return search(root->left, key);
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int KthSmallest(Node* root,int k){

    if(root == nullptr){
        return -1;
    }

    if(k==0)
    return root->data;

      if (root != nullptr)
    {
        KthSmallest(root->left,k--);
        cout << root->data << " ";

        KthSmallest(root->right,k--);
    }



}

void preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != nullptr)
    {

        inorder(root->left);
        inorder(root->right);
        cout << root->data << " ";
    }
}



int main()
{
    Node *root = nullptr;

    root = insert(root, 20);
    insert(root, 85);
    insert(root, 10);
    insert(root, 100);
    insert(root, 11);

    cout << "Inorder traversal of the BST: ";
    inorder(root);

    cout << "\nPreorder traversal of the BST: ";
    preorder(root);

    cout << "\nPostorder traversal of the BST: ";
    postorder(root);

    int ans = KthSmallest(root,2);
     cout <<"Kth smallest element is : " << ans << endl; 
    

    int key = 40;
    Node *result = search(root, key);

    if (result != nullptr)
    {
        cout << "\nKey " << key << " found in the BST." << endl;
    }
    else
    {
        cout << "\nKey " << key << " not found in the BST." << endl;
    }

    return 0;
}