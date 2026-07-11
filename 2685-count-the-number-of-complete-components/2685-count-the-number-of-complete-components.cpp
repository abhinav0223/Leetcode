class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            vector<int> comp;
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                comp.push_back(u);
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }

            long long vCount = comp.size();
            long long eCount = 0;
            for (int u : comp) eCount += adj[u].size();
            eCount /= 2;

            if (eCount == vCount * (vCount - 1) / 2) result++;
        }

        return result;
    }
};