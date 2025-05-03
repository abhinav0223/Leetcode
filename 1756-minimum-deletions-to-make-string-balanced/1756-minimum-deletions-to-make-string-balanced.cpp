class Solution {
public:
    int minimumDeletions(string s) {
        int left_b=0;
        int min_deletions=0;
        for(char c:s){
            if (c=='b'){
                left_b++;
            }
            else{
                min_deletions=min(min_deletions+1,left_b);
            }
        }
        return min_deletions;
    }
};