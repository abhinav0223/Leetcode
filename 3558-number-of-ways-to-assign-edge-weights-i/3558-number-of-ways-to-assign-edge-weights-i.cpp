class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDepth = 0;
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            maxDepth = max(maxDepth, depth[node]);
            for (int nb : adj[node]) {
                if (depth[nb] == -1) {
                    depth[nb] = depth[node] + 1;
                    q.push(nb);
                }
            }
        }

        long long ans = 1;
        for (int i = 0; i < maxDepth - 1; i++)
            ans = (ans * 2) % MOD;

        return (int)ans;
    }
};