class Solution {
    struct UnionFind {
        vector<int> parent, rnk;

        UnionFind(int n) : parent(n), rnk(n, 0) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (rnk[px] < rnk[py]) swap(px, py);
            parent[py] = px;
            if (rnk[px] == rnk[py]) rnk[px]++;
        }
    };

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);

        for (auto& sw : allowedSwaps)
            uf.unite(sw[0], sw[1]);

        unordered_map<int, unordered_map<int, int>> compFreq;
        for (int i = 0; i < n; i++)
            compFreq[uf.find(i)][source[i]]++;

        int hammingDist = 0;
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            auto& freq = compFreq[root];

            if (freq.count(target[i]) && freq[target[i]] > 0)
                freq[target[i]]--;
            else
                hammingDist++;
        }

        return hammingDist;
    }
};