class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long used = LLONG_MIN;
    int count = 0;

    for (int x : nums) {
        long long L = (long long)x - k;
        long long R = (long long)x + k;
        long long candidate = max(used + 1, L);

        if (candidate <= R) {
            used = candidate;
            count++;
        }
    }

    return count;
}

};