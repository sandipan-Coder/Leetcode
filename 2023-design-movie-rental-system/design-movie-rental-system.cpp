class MovieRentingSystem {

    unordered_map<int, unordered_map<int, int>> shopMovPric; // This store like : [shop] -> [movie] -> [price].
    unordered_map<int, set<pair<int, int>>> moviePricShop; // This store like :- [movie] -> {price, shop}.
    set<vector<int>> rentedMovie; // This store like :- {price, shop, movie}.

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        int m = entries.size();
        for(int i = 0; i < m; i++){
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];

            shopMovPric[shop][movie] = price;
            moviePricShop[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        
        vector<int> ans;
        if(!moviePricShop.count(movie))
            return ans;
        
        auto &st = moviePricShop[movie];

        for(auto it: st){
            int shop = it.second;
            ans.push_back(shop);
            if(ans.size() == 5)
                return ans;
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shopMovPric[shop][movie];

        moviePricShop[movie].erase({price, shop});
        rentedMovie.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopMovPric[shop][movie];

        moviePricShop[movie].insert({price, shop});
        rentedMovie.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        
        vector<vector<int>> ans;
        if(rentedMovie.size() == 0)
            return ans;
        
        for(auto &it: rentedMovie){

            int shop = it[1];
            int movie = it[2];
            ans.push_back({shop, movie});

            if(ans.size() == 5)
                return ans;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */