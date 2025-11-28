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

TreeNode* build(vector<int>& post, int ps, int pe, vector<int>& in, int is, int ie, unordered_map<int,int>& mp) {
    if (ps > pe || is > ie) return nullptr;
    int rootVal = post[pe];
    TreeNode* root = new TreeNode(rootVal);
    int k = mp[rootVal];
    int leftSize = k - is;
    root->left = build(post, ps, ps + leftSize - 1, in, is, k - 1, mp);
    root->right = build(post, ps + leftSize, pe - 1, in, k + 1, ie, mp);
    return root;
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    if (postorder.empty()) return nullptr;
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
    return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
}

void printPre(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPre(root->left);
    printPre(root->right);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> post(n), in(n);
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    TreeNode* root = buildTree(post, in);
    printPre(root);
    return 0;
}
