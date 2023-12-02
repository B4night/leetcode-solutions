#include "header.h"

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int store_chs[26] = { 0 };
        int ans = 0;
        for (auto& elem : chars) {
            store_chs[elem - 'a']++;
        }
        for (auto& elem1 : words) {
            int tmp_chs[26] = { 0 };
            for (auto& elem2 : elem1) {
                tmp_chs[elem2 - 'a']++;
            }
            int flag = 1;
            for (int i = 0; i < 26; i++) {
                if (!tmp_chs[i])
                    continue;
                if (tmp_chs[i] > store_chs[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans += elem1.size();
            }
        }
        return ans;
    }
};

int main() {

}