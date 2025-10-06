class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ls;
        int i,j;
        for(i=0;i<n;i++){
            int cnt=0;
            if(ls.size()==0 || ls[0]!=nums[i]){
            
                for(j=0;j<n;j++){
                    if(nums[j]==nums[i]){
                        cnt++;
                    }
                }
                    if(cnt>(n/3)){
                        ls.push_back(nums[i]);
                    }
                    if(ls.size()==2)
                    break;
                }
        }
                return ls;
            
        }

    };