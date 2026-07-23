class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 1;
        if (n==2) return 2;
        int bits=0;
        while ((1 << bits) <= n) bits++;
        int full = 1 << bits;
        return full;
    }
};