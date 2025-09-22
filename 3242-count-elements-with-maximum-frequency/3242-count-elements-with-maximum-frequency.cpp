class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {   
        unordered_map<int,int>f;
        for(int num:nums){
            f[num]++;
        }
        int maxf=0;
        for(auto &p:f){
            maxf=max(maxf,p.second);
        }
        int total=0;
        for(auto &p:f){
            if(p.second==maxf){
                total +=p.second;
            }
        }
        return total;      
    }
};