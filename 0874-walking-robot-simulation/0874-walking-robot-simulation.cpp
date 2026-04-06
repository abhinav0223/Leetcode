class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
    
        set<pair<int,int>> obsSet;
        for (auto& obs : obstacles)
            obsSet.insert({obs[0], obs[1]});
        
        int x = 0, y = 0, dir = 0;
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 3) % 4; 
            } else if (cmd == -1) {
                dir = (dir + 1) % 4; 
            } else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (obsSet.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};