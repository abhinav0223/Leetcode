class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; i++)
            valueToIndices[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            steps++;

            while (size--) {
                int idx = q.front(); q.pop();
                for (int next : {idx - 1, idx + 1}) {
                    if (next < 0 || next >= n) continue;
                    if (next == n - 1) return steps;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                if (valueToIndices.count(arr[idx])) {
                    for (int next : valueToIndices[arr[idx]]) {
                        if (next == n - 1) return steps;
                        if (!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                    valueToIndices.erase(arr[idx]);
                }
            }
        }

        return -1;
    }
};