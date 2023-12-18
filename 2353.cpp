#include "header.h"

class FoodRatings {
    class foodInfo {
    public:
        string name;
        string cuisine;
        int rating;

        foodInfo() {}

        foodInfo(string s, string c, int r) : name(s), cuisine(c), rating(r) {}

        bool operator < (const foodInfo& f) const {
            if (rating != f.rating) {
                return rating > f.rating;
            }
            return name < f.name;
        }

        bool operator == (const foodInfo& f) const {
            return name == f.name && cuisine == f.cuisine && rating == f.rating;
        }
    };
    unordered_map<string, foodInfo> foodToInfo;
    map<string, multiset<foodInfo>> cuisineToInfo;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int len = foods.size();
        for (int i = 0; i < len; i++) {
            foodInfo fi(foods[i], cuisines[i], ratings[i]);
            foodToInfo[foods[i]] = fi;
            cuisineToInfo[cuisines[i]].insert(fi);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuisine = foodToInfo[food].cuisine;
        cuisineToInfo[cuisine].erase(foodToInfo[food]);
        foodToInfo[food].rating = newRating;
        cuisineToInfo[cuisine].insert(foodToInfo[food]);
    }
    
    string highestRated(string cuisine) {
        return cuisineToInfo[cuisine].begin()->name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    vector<string> foods({"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"});
    vector<string> cuisines({"korean", "japanese", "japanese", "greek", "japanese", "korean"});
    vector<int> ratings({9, 12, 8, 15, 14, 7});
    // vector<string> foods({"miso", "sushi","ramen"});
    // vector<string> cuisines({"japanese", "japanese", "japanese"});
    // vector<int> ratings({12, 8, 14});
    FoodRatings* foodRatings = new FoodRatings(foods, cuisines, ratings);
    cout << foodRatings->highestRated("korean");
    cout << endl;
    cout << foodRatings->highestRated("japanese");
    cout << endl;
    foodRatings->changeRating("sushi", 16); // "sushi" now has a rating of 16.
    cout << foodRatings->highestRated("japanese"); // return "sushi"
                                        // "sushi" is the highest rated japanese food with a rating of 16.
    cout << endl;
    foodRatings->changeRating("ramen", 16); // "ramen" now has a rating of 16.
    cout << foodRatings->highestRated("japanese"); // return "ramen"
                                        // Both "sushi" and "ramen" have a rating of 16.
                                        // However, "ramen" is lexicographically smaller than 
}