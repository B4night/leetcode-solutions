#include "header.h"

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> m;
        vector<vector<int>> ans;
        for (auto& elem : nums)
            m[elem]++;
        while (!m.empty()) {
            vector<int> tmp;
            for (auto iter = m.begin(); iter != m.end();) {
                tmp.push_back(iter->first);
                iter->second--;
                if (iter->second == 0) {
                    auto old_iter = iter++;
                    m.erase(old_iter->first);
                    continue;
                }
                iter++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
    vector<int> v = {1, 3, 4, 1, 2, 3, 1};
    Solution().findMatrix(v);
}
