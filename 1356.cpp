#include "header.h"

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> v[32];
        for (auto& elem : arr) {
            int cnt = 0;
            int tmp = elem;
            while (tmp) {
                if (tmp & 0x1) {
                    cnt++;
                }
                tmp >>= 1;
            }
            v[cnt].push_back(elem);
        }
        vector<int> ans;
        for (int i = 0; i < 32; i++) {
            if (v[i].empty())
                continue;
            sort(v[i].begin(), v[i].end());
            ans.insert(ans.end(), v[i].begin(), v[i].end());
        }
        return ans;
    }
};

int main() {

}