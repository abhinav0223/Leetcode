class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int minval=nums[0];
        int maxdiff=-1;

        for(int i=1;i<nums.size();++i){
            if(nums[i]>minval){
                maxdiff=max(maxdiff,nums[i]-minval);

            } else{
                minval=nums[i];          }
        }
        return maxdiff;
    }

};