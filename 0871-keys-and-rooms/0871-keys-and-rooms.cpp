class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<char> visited(n,false);
        queue<int> q;
        visited[0]=true;
        q.push(0);
        int visitedcount=1;
        while(!q.empty()){
            int cur=q.front(); q.pop();

            for(int key:rooms[cur]){
                if(!visited[key]){
                    visited[key]=true;
                    q.push(key);
                    ++visitedcount;
                }
                else{
            }
        }
        
    }
    if(visitedcount==n){
        return true;
    }
    else{
        return false;
    }
    }
};
