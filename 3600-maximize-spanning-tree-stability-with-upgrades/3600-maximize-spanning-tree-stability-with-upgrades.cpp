class Solution {
public:
    struct DSU {
        vector<int> parent, rank_;
        int components;
        DSU(int n) : parent(n), rank_(n, 0), components(n) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            x = find(x); y = find(y);
            if (x == y) return false;
            if (rank_[x] < rank_[y]) swap(x, y);
            parent[y] = x;
            if (rank_[x] == rank_[y]) rank_[x]++;
            components--;
            return true;
        }
    };

    bool canAchieve(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);

        for (auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < mid) return false;
                if (!dsu.unite(e[0], e[1])) return false;
            }
        }

        for (auto& e : edges) {
            if (e[3] == 0 && e[2] >= mid) {
                dsu.unite(e[0], e[1]);
            }
        }
        int upgradesUsed = 0;
        for (auto& e : edges) {
            if (e[3] == 0 && e[2] < mid && e[2] * 2 >= mid) {
                if (dsu.find(e[0]) != dsu.find(e[1])) {
                    if (upgradesUsed == k) continue;
                    upgradesUsed++;
                    dsu.unite(e[0], e[1]);
                }
            }
        }

        return dsu.components == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        if (!canAchieve(n, edges, k, 0)) return -1;

        int lo = 1, hi = 200000, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canAchieve(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};