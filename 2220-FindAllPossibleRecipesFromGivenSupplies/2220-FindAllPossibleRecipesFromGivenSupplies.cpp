// Last updated: 10/5/2025, 8:53:11 AM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(begin(supplies), end(supplies));  // Available ingredients
        unordered_set<string> st1(begin(recipes), end(recipes));   // Set of recipes
        vector<string> res;
        bool flag = true;  // Tracks if any new recipe is added in a pass

        while (flag) {  
            flag = false;  
            for (int i = 0; i < recipes.size(); i++) {
                if (st.find(recipes[i]) != st.end()) continue; // Skip if already available

                bool canMake = true;
                for (const string& ingredient : ingredients[i]) {
                    if (st.find(ingredient) == st.end()) {  
                        canMake = false;
                        break;  
                    }
                }
                
                if (canMake) {
                    res.push_back(recipes[i]);
                    st.insert(recipes[i]);  // Add recipe to available set
                    flag = true;  // Mark that we added a new recipe
                }
            }
        }
        return res;
    }
};
