#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find and print leaf nodes of the binary tree
void findLeafNodes(TreeNode* root) {
    // Base case: if the node is nullptr, return
    if (root == nullptr) {
        return;
    }
    
    // If it's a leaf node (no left or right children), print its value
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->val << " ";
        return;
    }
    
    // Recurse through the left and right subtrees
    findLeafNodes(root->left);
    findLeafNodes(root->right);
}

int main() {
    // Example Tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //             \
    //              7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    
    cout << "Leaf Nodes of the Binary Tree: ";
    findLeafNodes(root);
    cout << endl;
    
    return 0;
}
