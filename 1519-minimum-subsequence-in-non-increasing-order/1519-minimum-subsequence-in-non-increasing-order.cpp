class Solution {
public:
   vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());  
    vector<int> result;
    int totalSum = 0, subSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    for (int num : nums) {
        subSum += num;
        result.push_back(num);
        if (subSum > totalSum - subSum) {
            break;
        }
    }
    return result;
}
};