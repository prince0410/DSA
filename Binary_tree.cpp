#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *create()
{

    int data;

    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node;
    root->data = data;

    cout << "insert node at left of " << data << " : ";
    root->left = create();

    cout << "insert node at right of " << data << " : ";
    root->right = create();

    return root;
}

int DepthOfTree(Node *root)
{

    queue<struct Node *> q;
    int depth = 0;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            depth++;
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {

            if (temp->right != nullptr)
                q.push(temp->left);

            if (temp->left != nullptr)
                q.push(temp->left);
        }
    }

    return depth;
}

int Depth_Recursion(Node* root){

if(root == nullptr)
return 0;

int l = Depth_Recursion(root->left);
int r = Depth_Recursion(root->left);

return max(l,r)+1;

}

void preorder(Node* root){

if(root != nullptr){

cout << root->data << " ";
preorder(root->left);
preorder(root->right);

}


}

int main()
{

    Node *p = create();

    // int depth = DepthOfTree(p);
    int depth =  Depth_Recursion(p);

    cout << "preorder is : ";

    preorder(p);

    cout << endl;

    cout << "Depth is : " << depth << endl;




}