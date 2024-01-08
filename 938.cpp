#include "header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        traverse(root, low, high);
        return ans;
    }
    void traverse(TreeNode* r, int lo, int hi) {
        if (r == nullptr) {
            return;
        }
        if (r->val <= hi && r->val >= lo) {
            ans += r->val;
        }
        traverse(r->left, lo, hi);
        traverse(r->right, lo, hi);
    }
};

int main() {

}