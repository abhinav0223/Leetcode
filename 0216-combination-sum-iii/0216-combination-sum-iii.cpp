class Solution {
public:
void backtrack(int k,int n,int start,vector<int>& comb,vector<vector<int>>& result){
    if(comb.size()==k && n==0){
        result.push_back(comb);
        return;
    }
    if (comb.size()>k||n<0) return;
    for(int i=start;i<=9;++i)
    {
    comb.push_back(i);
    backtrack(k,n-i,i+1,comb,result);
    comb.pop_back();
}
}
       vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> comb;
        backtrack(k, n, 1, comb, result);
        return result;
        
    }
};
