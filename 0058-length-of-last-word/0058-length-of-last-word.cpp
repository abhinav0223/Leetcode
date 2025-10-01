class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.find_last_not_of(' ');
        int start=s.find_last_of(' ',end);
        return (end-start);
        
    }
};