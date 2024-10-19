#include <iostream>
using namespace std;

// Binary Search Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a node in BST
Node* insertBST(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else if (val > root->data) {
        root->right = insertBST(root->right, val);
    }
    
    return root;
}

// Search a node in BST
Node* searchBST(Node* root, int val) {
    if (root == nullptr || root->data == val) {
        return root;
    }
    
    if (val < root->data) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

// Inorder Traversal (LNR)
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Driver code
int main() {
    Node* root = nullptr;
    
    // Insert nodes into BST
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 60);
    root = insertBST(root, 80);
    
    // Display BST in Inorder Traversal
    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << "\n";
    
    // Search a node
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    
    Node* searchResult = searchBST(root, val);
    if (searchResult != nullptr) {
        cout << "Node found: " << searchResult->data << "\n";
    } else {
        cout << "Node not found\n";
    }

    cout << endl;

        cout << "prepred by 23CE140_Prince" << endl;


    return 0;
}
