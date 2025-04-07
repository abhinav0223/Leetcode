class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum=accumulate(nums.begin(), nums.end(),0L);
        int min_Val= *min_element(nums.begin(),nums.end());
        return static_cast<int>(sum-static_cast<long>(nums.size())*min_Val);
    }
};