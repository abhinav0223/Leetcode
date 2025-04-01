class Solution {
public:
    string frequencySort(string s) {
          unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    vector<pair<char, int>> charFreq(freq.begin(), freq.end());
    sort(charFreq.begin(), charFreq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });
    string result;
    for (auto& p : charFreq) {
        result.append(p.second, p.first);
    }
    
    return result;
}
        
    
};