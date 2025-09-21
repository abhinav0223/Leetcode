class MovieRentingSystem {
private:
    unordered_map<int, unordered_map<int, int>> price;   
    unordered_map<int, set<pair<int,int>>> available;  
    set<tuple<int,int,int>> rented;                     

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            price[shop][movie] = p;
            available[movie].insert({p, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        for (auto& [p, s] : available[movie]) {
            if (count == 5) break;
            result.push_back(s);
            count++;
        }
        return result;
    }

    void rent(int shop, int movie) {
        int p = price[shop][movie];
        available[movie].erase({p, shop});           
        rented.insert({p, shop, movie});            
    }

    void drop(int shop, int movie) {
        int p = price[shop][movie];
        rented.erase({p, shop, movie});        
        available[movie].insert({p, shop});          
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto& [p, s, m] : rented) {
            if (count == 5) break;
            result.push_back({s, m});
            count++;
        }
        return result;
    }
};
