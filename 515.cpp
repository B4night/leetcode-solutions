#include "header.h"

class Solution {
    map<int, int> m;
public:
    vector<int> largestValues(TreeNode* root) {
        traverse(root, 0);
        vector<int> ans;
        for (auto& elem : m) {
            ans.push_back(elem.second);
        }
        return ans;
    }
    void traverse(TreeNode* p, int depth) {
        if (!p) {
            return;
        }
        if (m.count(depth) == 0 || p->val > m[depth]) {
            m[depth] = p->val;
        }
        traverse(p->left, depth + 1);
        traverse(p->right, depth + 1);
    }
};