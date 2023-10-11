#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        std::map<int, int> counts;      // counts[people time] = number of flowers
        std::vector<int> sortedPeople = people;
        std::sort(sortedPeople.begin(), sortedPeople.end());
        for (auto& elem : sortedPeople) {
            counts[elem];
        }
       
        std::sort(flowers.begin(), flowers.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> endTime;  
        // use min heap to store all the end time of the selected elements.

        size_t flowerIdx = 0;   // index for vector flowers
        for (auto& elem : counts) {
            // store all the elements whose start time is smaller than people's arrive time
            while (flowerIdx < flowers.size() && flowers[flowerIdx][0] <= elem.first) {
                endTime.push(flowers[flowerIdx][1]);
                flowerIdx++;
            }
            /**
             * According to the fact that elem.first is an ascending sequence
             * We can get the result that at this point, min heap stores 2 kinds of flowers
             * 1. This kind of flowers' end time is smaller than elem.first(people's arrive time)
             * 2. this kind of flowers' end time is larger than elem.first
             * 
             * Note: We need to keep in mind that all the flowers' start time is smaller than elem.first 
            */

            // now we need to pop the first kind of flower. 
            // Which means we need to evict flowers whose end time is smaller than elem.first
            while (!endTime.empty() && endTime.top() < elem.first) 
                endTime.pop();

            /**
             * At this point, we can assure that all the flowers in min heap satisfy 2 conditions:
             * 1. their start time <= elem.first
             * 2. their end time >= elem.first
             * Which means the size of the min heap is the number of flowers people can see when they arrive
            */
            elem.second = endTime.size();
        }


        std::vector<int> res;
        for (auto& elem : people) {
            res.push_back(counts[elem]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> v = {{21,34},{17,37},{23,43},{17,46},{37,41},{44,45},{32,45}};
    vector<int> v2 = {31,41,10,12};
    Solution().fullBloomFlowers(v, v2);
}