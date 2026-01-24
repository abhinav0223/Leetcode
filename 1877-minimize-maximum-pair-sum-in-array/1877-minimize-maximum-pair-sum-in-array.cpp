class Solution {
public:
    int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());  
    
    int i = 0;
    int j = nums.size() - 1;
    int maxPairSum = 0;

    while (i < j) {
        int pairSum = nums[i] + nums[j];
        maxPairSum = max(maxPairSum, pairSum);
        i++;
        j--;
    }

    return maxPairSum;
}

};