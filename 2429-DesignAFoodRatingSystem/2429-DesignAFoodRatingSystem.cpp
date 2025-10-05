// Last updated: 10/5/2025, 8:52:22 AM
class FoodRatings {
public:
      unordered_map<string,int>food_ratings;
        unordered_map<string , set<pair<int,string>>>cusine_rating_food;
        unordered_map<string,string>food_cusine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0 ; i<n ; i++)
        {
            string food = foods[i];
           string cuisine = cuisines[i];
           int rating = ratings[i];
            food_ratings[food] = rating ;
            cusine_rating_food[cuisine].insert({-rating , food});
            food_cusine[food] = cuisine ;
            
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cusine[food];
        int old_rating = food_ratings[food];
        food_ratings[food] = newRating;
        cusine_rating_food[cuisine].erase({-old_rating , food});
        cusine_rating_food[cuisine].insert({-newRating , food});

        
    }
    
    string highestRated(string cuisine) {

        return begin(cusine_rating_food[cuisine]) -> second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */