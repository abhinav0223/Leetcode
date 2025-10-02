class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> pq;
        for(int num:nums){
        if(num>0)
        pq.insert(num);
        }
        return pq.size();
        
    }
};