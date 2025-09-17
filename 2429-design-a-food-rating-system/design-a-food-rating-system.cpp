struct cmp {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) const {
        if(a.first != b.first)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
};

class FoodRatings {
    unordered_map<string, int> foodToRating;
    unordered_map<string, string> foodToCuisines;
    unordered_map<string, set<pair<int, string>, cmp>> cuisinesToRatings; // {cuisines -> {ratings, foods}}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        // This store the foods -> ratings 
        for(int i = 0; i < n; i++)
            foodToRating[foods[i]] = ratings[i];

        // This store the foods -> cuisines
        for(int i = 0; i < n; i++)   
            foodToCuisines[foods[i]] = cuisines[i];

        // This store the {cuisines -> {ratings, foods}}
        for(int i = 0; i < n; i++){
            cuisinesToRatings[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        
        string cuisine = foodToCuisines[food];
        int oldRating = foodToRating[food];
        cuisinesToRatings[cuisine].erase({oldRating, food});
        
       cuisinesToRatings[cuisine].insert({newRating, food});
       foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        
        return cuisinesToRatings[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */