#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Utility function to insert nodes (for testing)
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// (Main logic) Function to check if a tree is BST
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Left subtree must be within (min, root->data)
    // Right subtree must be within (root->data, max)
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

// Wrapper function
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Inorder traversal (to visualize tree)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    // Example 1: A valid BST
    Node* root1 = nullptr;
    root1 = insert(root1, 50);
    insert(root1, 30);
    insert(root1, 70);
    insert(root1, 20);
    insert(root1, 40);
    insert(root1, 60);
    insert(root1, 80);

    cout << "Inorder traversal of Tree 1: ";
    inorder(root1);
    cout << "\nTree 1 is " << (isBST(root1) ? "a BST" : "NOT a BST") << endl;

    // Example 2: A non-BST
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(8); // Violation: 8 < 10 but in right subtree

    cout << "\nInorder traversal of Tree 2: ";
    inorder(root2);
    cout << "\nTree 2 is " << (isBST(root2) ? "a BST" : "NOT a BST") << endl;

    return 0;
}
