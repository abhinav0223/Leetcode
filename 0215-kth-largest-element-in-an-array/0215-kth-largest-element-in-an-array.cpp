class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       // sort(nums.begin(),nums.end(),greater<int>());
        //return nums[k-1];
        

        priority_queue<int,vector<int>,greater<int>> minHeap;

        for(int num:nums){
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();

    }
};