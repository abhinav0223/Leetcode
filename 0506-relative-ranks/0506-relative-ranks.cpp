class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    vector<int> sortedScore = score;  
    sort(sortedScore.rbegin(), sortedScore.rend());  
    unordered_map<int, string> rankMap; 
    for (int i = 0; i < n; i++) {
        if (i == 0)
            rankMap[sortedScore[i]] = "Gold Medal";
        else if (i == 1)
            rankMap[sortedScore[i]] = "Silver Medal";
        else if (i == 2)
            rankMap[sortedScore[i]] = "Bronze Medal";
        else
            rankMap[sortedScore[i]] = to_string(i + 1);
    }
    
    // Build the result based on the original order
    vector<string> result;
    for (int s : score) {
        result.push_back(rankMap[s]);
    }
    
    return result;
}
};