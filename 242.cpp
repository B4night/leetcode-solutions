#include "header.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        for (auto& elem : s) {
            um[elem]++;
        }
        for (auto& elem : t) {
            if (!um.count(elem)) {
                return false;
            }
            um[elem]--;
            if (um[elem] == 0) {
                um.erase(elem);
            }
        }
        return um.empty();
    }
};

int main() {
    
}
