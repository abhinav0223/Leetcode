class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_unique = arr;
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());
        
        unordered_map<int, int> rank;
        for (int i = 0; i < sorted_unique.size(); i++) {
            rank[sorted_unique[i]] = i + 1;
        }
        
        vector<int> result;
        result.reserve(arr.size());
        for (int x : arr) {
            result.push_back(rank[x]);
        }
        
        return result;
    }
};