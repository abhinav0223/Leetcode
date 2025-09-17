class FoodRatings {
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;
    // cuisine -> ordered set of (rating, food) with custom comparator
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second; 
        }
    };
    unordered_map<string, set<pair<int, string>, Compare>> cuisineSets;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineSets[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    // Change rating of a food
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        // Remove old rating
        cuisineSets[cuisine].erase({oldRating, food});
        // Update
        foodInfo[food].second = newRating;
        // Insert new rating
        cuisineSets[cuisine].insert({newRating, food});
    } 
    // Get highest rated food for a cuisine
    string highestRated(string cuisine) {
        return cuisineSets[cuisine].begin()->second;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */