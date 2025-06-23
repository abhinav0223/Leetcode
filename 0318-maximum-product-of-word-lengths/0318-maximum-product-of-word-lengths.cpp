class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n,0);
        vector<int> lengths(n,0);

        for(int i =0;i<n;i++){
            int mask=0;
            for(char c:words[i]){
                mask |=1<<(c-'a');
            }
            masks[i]=mask;
            lengths[i]=words[i].length();
        }
        int maxProduct=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((masks[i] & masks[j])==0){
                    int product=lengths[i]*lengths[j];
                    maxProduct=max(maxProduct,product);
                }
            }
        }
        return maxProduct;
    }
};