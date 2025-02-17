class Solution {
public:
    
void dfs(string& tiles, vector<bool>& used, string current, unordered_set<string>& sequences) {
    if (!current.empty()) {
        sequences.insert(current);
    }
    for (size_t i = 0; i < tiles.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        dfs(tiles, used, current + tiles[i], sequences);
        used[i] = false;
    }
}
int numTilePossibilities(string tiles) {

    sort(tiles.begin(), tiles.end());
    unordered_set<string> sequences;

    vector<bool> used(tiles.size(), false);   
    dfs(tiles, used, "", sequences);
    
    return sequences.size();
   }
   };