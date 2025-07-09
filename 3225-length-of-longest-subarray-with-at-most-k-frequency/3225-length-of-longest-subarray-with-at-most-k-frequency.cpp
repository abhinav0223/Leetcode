class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int j=0;
        int maxLen=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;

                while(freq[nums[i]]>k){
                    freq[nums[j]]--;
                    j++;
                }
        maxLen=max(maxLen,i-j+1);
            }
            return maxLen;
        }
        
    };
   