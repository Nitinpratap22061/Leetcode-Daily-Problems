// Last updated: 9/22/2025, 2:13:12 AM
typedef pair<int,int> P; 
unordered_map<int , set<P>> available;   // movie -> {price , shop}
unordered_map<int , set<P>> moviestoshop; // movie -> {shop , price}
set<tuple<int,int,int>> helper; // {price , shop , movie}

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        available.clear();
        moviestoshop.clear();
        helper.clear();

        for(auto &e : entries) {
            int shop = e[0]; 
            int movie = e[1]; 
            int price = e[2]; 

            available[movie].insert({price , shop}); 
            moviestoshop[movie].insert({shop , price}); 
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res; 
        int count = 0; 
        if(available.count(movie)) {
            for(auto &[price , shop] : available[movie]) {
                res.push_back(shop); 
                count++; 
                if(count >= 5) break; 
            }
        }
        return res; 
    }
    
    void rent(int shop, int movie) {
        auto it = moviestoshop[movie].lower_bound({shop , INT_MIN});
        if(it == moviestoshop[movie].end() || it->first != shop) return; // safety

        int price = it->second; 
        available[movie].erase({price , shop}); 
        helper.insert({price , shop , movie}); 
    }
    
    void drop(int shop, int movie) {
        auto it = moviestoshop[movie].lower_bound({shop , INT_MIN});
        if(it == moviestoshop[movie].end() || it->first != shop) return; // safety

        int price = it->second; 
        available[movie].insert({price , shop}); 
        helper.erase({price , shop , movie}); 
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result; 
        int count = 0; 
        for(auto &[price , shop , movie] : helper) {
            result.push_back({shop , movie}); 
            count++; 
            if(count >= 5) break; 
        }
        return result; 
    }
};
