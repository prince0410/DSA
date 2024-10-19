#include <iostream>
#include <queue>
using namespace std;

// Binary Tree Node
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

// Insert a node at Left of the root
Node* insertLeft(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    } else if (root->left == nullptr) {
        root->left = new Node(val);
    } else {
        cout << "Left child already exists\n";
    }
    return root;
}

// Delete the right child of the root
Node* deleteRight(Node* root) {
    if (root != nullptr && root->right != nullptr) {
        delete root->right;
        root->right = nullptr;
    }
    return root;
}

// Inorder Traversal
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal
void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// Driver code
int main() {
    // Creating the root node
    Node* root = new Node(1);
    
    // Insert node at left of the root
    insertLeft(root, 2);
    
    // Insert node at right of the root (manually for demonstration)
    root->right = new Node(3);

    // Display traversals
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << "\n";
    
    // Delete right node of the root
    deleteRight(root);
    
    // Display traversals after deletion
    cout << "\nAfter deleting right child:\n";
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << "\n";

    cout << "prepred by 23CE140_Prince" << endl;
    
    return 0;
}
