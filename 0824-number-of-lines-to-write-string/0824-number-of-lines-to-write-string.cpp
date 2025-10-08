class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int cwidth=0;
        int lines=1;
        for(char c:s){
            int w=widths[c-'a'];
            if(cwidth+w>100){
                lines++;
                cwidth=w;
            }
            else{
                cwidth +=w;
            }
        }
         return{lines,cwidth};
    }
};