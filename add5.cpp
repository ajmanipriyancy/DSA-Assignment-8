#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie, unordered_map<int,int>& mp) {
    if (ps > pe || is > ie) return nullptr;
    TreeNode* root = new TreeNode(pre[ps]);
    int k = mp[pre[ps]];
    int left = k - is;
    root->left = build(pre, ps + 1, ps + left, in, is, k - 1, mp);
    root->right = build(pre, ps + left + 1, pe, in, k + 1, ie, mp);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
}

void printPost(TreeNode* root) {
    if (!root) return;
    printPost(root->left);
    printPost(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> pre(n), in(n);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    TreeNode* root = buildTree(pre, in);
    printPost(root);
}
