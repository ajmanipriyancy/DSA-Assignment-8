#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int x) {
    if (!root) return new TreeNode(x);
    if (x < root->val) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

pair<TreeNode*, TreeNode*> treeToDLL(TreeNode* root) {
    if (!root) return {nullptr, nullptr};
    auto L = treeToDLL(root->left);
    auto R = treeToDLL(root->right);
    if (L.second) {
        L.second->right = root;
        root->left = L.second;
    } else root->left = nullptr;
    if (R.first) {
        R.first->left = root;
        root->right = R.first;
    } else root->right = nullptr;
    TreeNode* head = L.first ? L.first : root;
    TreeNode* tail = R.second ? R.second : root;
    return {head, tail};
}

TreeNode* mergeDLL(TreeNode* a, TreeNode* b) {
    if (!a) return b;
    if (!b) return a;
    TreeNode dummy(0);
    TreeNode* cur = &dummy;
    while (a && b) {
        if (a->val <= b->val) {
            cur->right = a;
            a->left = cur;
            a = a->right;
        } else {
            cur->right = b;
            b->left = cur;
            b = b->right;
        }
        cur = cur->right;
    }
    if (a) cur->right = a, a->left = cur;
    if (b) cur->right = b, b->left = cur;
    TreeNode* head = dummy.right;
    if (head) head->left = nullptr;
    return head;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    TreeNode* root1 = nullptr;
    for (int i = 0; i < n; i++) { int x; cin >> x; root1 = insertBST(root1, x); }
    int m;
    cin >> m;
    TreeNode* root2 = nullptr;
    for (int i = 0; i < m; i++) { int x; cin >> x; root2 = insertBST(root2, x); }
    TreeNode* head1 = treeToDLL(root1).first;
    TreeNode* head2 = treeToDLL(root2).first;
    TreeNode* head = mergeDLL(head1, head2);
    for (TreeNode* p = head; p; p = p->right) cout << p->val << " ";
    return 0;
}
