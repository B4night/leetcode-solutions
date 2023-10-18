#include "header.h"

class Solution {
    std::map<int, vector<int>> m;   // m[i] is a vector of prerequisites of course i
    bool visit[50005];
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        std::vector<int> v(time);   // v[i] means the minimun time course i needs
        memset(visit, 0, sizeof(visit));    // visit[i] = true means v[i] is the minimun num
        for (auto& elem : relations) {
            m[elem[1] - 1].push_back(elem[0] - 1);
        }

        for (int i = 0; i < n; i++) {
            if (m.count(i))
                continue;
            visit[i] = true;
        }
        
        for (int i = 0; i < n; i++) {
            if (visit[i]) {
                continue;
            }
            __recur(i, v);
        }

        return *std::max_element(v.begin(), v.end());
    }
    void __recur(int idx, vector<int>& time) {
        int cnt = 0;
        for (auto& elem : m[idx]) {
            if (!visit[elem]) {
                __recur(elem, time);
                visit[elem] = true;
            }
            cnt = max(cnt, time[elem]);
        }
        time[idx] += cnt;
        visit[idx] = true;
    }
};

int main() {
    vector<vector<int>> v1 = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> time = {1, 2, 3, 4, 5};
    int n = 5;
    cout << Solution().minimumTime(n, v1, time);
}