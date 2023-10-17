#include "header.h"

/**
 * First, we have to fine the root
 * Then, we apply BFS to root node
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // Get root, use indegree array to determine whether there's a edge links the node
        int indegree[10005] = { 0 };
        int root = -1;
        for (int i = 0; i < n; i++) {
            int l = leftChild[i];
            int r = rightChild[i];
            if (l != -1)
                indegree[l]++;
            if (r != -1)
                indegree[r]++;
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) {
                    return false;   // multiple root nodes
                }
                root = i;
            }
        }

        if (root == -1)
            return false;

        // use BFS to find
        bool visit[10005];
        int cnt = 0;
        memset(visit, 0 , sizeof(visit));
        queue<int> q;
        q.push(root);
        visit[root] = true;
        cnt++;
        while (q.size()) {
            int tmp = q.front();
            q.pop();
            int l = leftChild[tmp];
            int r = rightChild[tmp];
            if (l != -1) {
                if (visit[l]) {
                    return false;
                }
                visit[l] = true;
                q.push(l);
                cnt++;
            }
            if (r != -1) {
                if (visit[r]) {
                    return false;
                }
                visit[r] = true;
                q.push(r);
                cnt++;
            }
        }
        return cnt == n;
    }
};

int main() {
    int n = 4;
    vector<int> l = {1,-1,3,-1};
    vector<int> r = {2,-1,-1,-1};
    cout << Solution().validateBinaryTreeNodes(n, l, r);
}