class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
          std::vector<int> sub;
    for (int num : nums) {
        auto it = std::lower_bound(sub.begin(), sub.end(), num);
        if (it == sub.end()) {
            sub.push_back(num);
        } else {
            *it = num;
        }
    }
    return sub.size();
}
        
};