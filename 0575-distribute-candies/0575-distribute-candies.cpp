class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
 sort(candyType.begin(), candyType.end());
    int uniqueCount = 1; 
    for (size_t i = 1; i < candyType.size(); i++) {
        if (candyType[i] != candyType[i - 1]) {
            uniqueCount++;
        }
    }

    return min(uniqueCount, (int)candyType.size() / 2);
}
};