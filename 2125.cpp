#include "header.h"

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> num;
        int ans = 0;
        for (auto& elem : bank) {
            int cnt = 0;
            for (auto& ch : elem) {
                if (ch == '1')
                    cnt++;
            }
            num.push_back(cnt);
        }
        int fntIdx = 0;
        int lstIdx;
        while (fntIdx < bank.size() && num[fntIdx] == 0) {
            fntIdx++;
        }
        lstIdx = fntIdx + 1;

        while (lstIdx < bank.size()) {
            if (num[lstIdx] != 0) {
                ans += num[fntIdx] * num[lstIdx];
                fntIdx = lstIdx;
                lstIdx = fntIdx + 1;
                continue;
            }
            lstIdx++;
        }
        return ans;
    }
};

int main() {

}