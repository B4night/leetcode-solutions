#include "header.h"

/**
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
*/

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    vector<int> flattenVals;        // this is the flattened value of Nested lists
    int idx = 0;                    // index indicates the location
    void flatten(const vector<NestedInteger> &nestedList) {
        for (auto& elem : nestedList) {
            if (elem.isInteger()) {
                flattenVals.push_back(elem.getInteger());
            } else {    // recursively execute when operating with nested lists
                flatten(elem.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        idx = 0;
    }
    
    int next() {
        int ans = flattenVals[idx++];
        return ans;
    }
    
    bool hasNext() {
        return idx != flattenVals.size();
    }
};

/**
Your NestedIterator object will be instantiated and called as such:
NestedIterator i(nestedList);
while (i.hasNext()) cout << i.next();
 */

int main() {

}