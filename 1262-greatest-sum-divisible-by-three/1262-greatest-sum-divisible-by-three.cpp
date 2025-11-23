class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> mod1, mod2;

        for (int n : nums) {
            sum += n;
            if (n % 3 == 1) mod1.push_back(n);
            else if (n % 3 == 2) mod2.push_back(n);
        }

        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if (sum % 3 == 0) return sum;

        int ans = 0;

        if (sum % 3 == 1) {
            int remove1 = (mod1.size() > 0 ? mod1[0] : INT_MAX);
            int remove2 = (mod2.size() > 1 ? mod2[0] + mod2[1] : INT_MAX);
            ans = sum - min(remove1, remove2);
        } 
        else { 
            int remove1 = (mod2.size() > 0 ? mod2[0] : INT_MAX);
            int remove2 = (mod1.size() > 1 ? mod1[0] + mod1[1] : INT_MAX);
            ans = sum - min(remove1, remove2);
        }

   
        return (ans < 0 ? 0 : ans);
    }
};