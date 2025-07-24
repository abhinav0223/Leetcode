class Solution {
public:
    vector<vector<int>> tree;
    vector<int> subtreeXor;
    vector<int> inTime, outTime;
    int time = 0;
    int totalXor;

    void dfs(int node, int parent, const vector<int>& nums) {
        inTime[node] = time++;
        subtreeXor[node] = nums[node];
        for (int neighbor : tree[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, nums);
                subtreeXor[node] ^= subtreeXor[neighbor];
            }
        }
        outTime[node] = time++;
    }

    bool isAncestor(int u, int v) {
        return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, vector<int>());
        subtreeXor.resize(n);
        inTime.resize(n);
        outTime.resize(n);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, nums);
        totalXor = subtreeXor[0];

        int minScore = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a, b, c;

                if (isAncestor(i, j)) {
                    a = subtreeXor[j];
                    b = subtreeXor[i] ^ subtreeXor[j];
                    c = totalXor ^ subtreeXor[i];
                } else if (isAncestor(j, i)) {
                    a = subtreeXor[i];
                    b = subtreeXor[j] ^ subtreeXor[i];
                    c = totalXor ^ subtreeXor[j];
                } else {
                    a = subtreeXor[i];
                    b = subtreeXor[j];
                    c = totalXor ^ subtreeXor[i] ^ subtreeXor[j];
                }

                int score = max({a, b, c}) - min({a, b, c});
                minScore = min(minScore, score);
            }
        }

        return minScore;
    }
};