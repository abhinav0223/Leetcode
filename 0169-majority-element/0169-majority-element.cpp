class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int i,j;
for(i=0;i<n;i++){
    int cnt=0;
    for(j=0;j<n;j++) {
        if(nums[i]==nums[j]){
        cnt++;
    }
    }
    if(cnt>n/2){
        return nums[i];
    }

        
    }
    return 0;
    }
};