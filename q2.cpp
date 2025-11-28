#include <iostream>
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

// Function to insert a node into BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// (a) Search (Recursive)
Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search (Non-Recursive)
Node* searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

// (b) Maximum element of BST
Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// (c) Minimum element of BST
Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// (d) Inorder Successor of a given node
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != nullptr)
        return findMin(target->right);

    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != target) {
        if (target->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// (e) Inorder Predecessor of a given node
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != nullptr)
        return findMax(target->left);

    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != target) {
        if (target->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

// Inorder Traversal (for display)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << "\n";

    int key = 40;
    // (a) Search
    Node* foundRec = searchRecursive(root, key);
    Node* foundNonRec = searchNonRecursive(root, key);
    cout << "\nSearch (Recursive): " << (foundRec ? "Found" : "Not Found");
    cout << "\nSearch (Non-Recursive): " << (foundNonRec ? "Found" : "Not Found");

    // (b) Maximum
    cout << "\nMaximum element: " << findMax(root)->data;

    // (c) Minimum
    cout << "\nMinimum element: " << findMin(root)->data;

    // (d) Inorder Successor
    Node* target = searchRecursive(root, 60);
    Node* succ = inorderSuccessor(root, target);
    if (succ)
        cout << "\nInorder Successor of " << target->data << " is " << succ->data;
    else
        cout << "\nInorder Successor of " << target->data << " does not exist.";

    // (e) Inorder Predecessor
    Node* pred = inorderPredecessor(root, target);
    if (pred)
        cout << "\nInorder Predecessor of " << target->data << " is " << pred->data;
    else
        cout << "\nInorder Predecessor of " << target->data << " does not exist.";

    cout << endl;
    return 0;
}
