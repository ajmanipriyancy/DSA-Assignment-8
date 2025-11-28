#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> build(int s, int e) {
    if (s > e) return {nullptr};
    vector<TreeNode*> res;
    for (int i = s; i <= e; i++) {
        vector<TreeNode*> L = build(s, i - 1);
        vector<TreeNode*> R = build(i + 1, e);
        for (TreeNode* l : L) for (TreeNode* r : R) {
            TreeNode* root = new TreeNode(i);
            root->left = l;
            root->right = r;
            res.push_back(root);
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return build(1, n);
}

void serializePreorder(TreeNode* root) {
    if (!root) {
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    serializePreorder(root->left);
    serializePreorder(root->right);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<TreeNode*> ans = generateTrees(n);
    cout << ans.size() << "\n";
    for (TreeNode* t : ans) {
        serializePreorder(t);
        cout << "\n";
    }
    return 0;
}
