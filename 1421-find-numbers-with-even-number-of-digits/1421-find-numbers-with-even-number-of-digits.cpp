class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int num:nums){
            int num_digits=log10(num)+1;
            if(num_digits%2==0){
                cnt++;
            }
        }
        return cnt;
        
    }
  
};