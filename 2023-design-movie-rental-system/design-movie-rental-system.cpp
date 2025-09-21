class MovieRentingSystem {
    map<int, set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;
    map<pair<int,int>, int> priceMap;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price, shop});
            priceMap[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            for (auto &p : available[movie]) {
                res.push_back(p.second);
                if (res.size() == 5) break;
            }
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto &t : rented) {
            res.push_back({get<1>(t), get<2>(t)});
            if (res.size() == 5) break;
        }
        return res;
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