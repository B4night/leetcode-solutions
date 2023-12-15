#include "header.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> isDest;
        map<string, string> from_to;
        string begin;
        for (auto& elem : paths) {
            isDest.insert(elem[1]);
            from_to[elem[0]] = elem[1];
        }  
        for (auto& elem : paths) {
            if (isDest.count(elem[0]))
                continue;
            begin = elem[0];
            break;
        }
        while (from_to.count(begin)) {
            begin = from_to[begin];
        }
        return begin;
    }
};

int main() {

}