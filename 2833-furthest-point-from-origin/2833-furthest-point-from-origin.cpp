class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = count(moves.begin(), moves.end(), 'L');
        int R = count(moves.begin(), moves.end(), 'R');
        int blanks = count(moves.begin(), moves.end(), '_');
        return abs(L - R) + blanks;
    }
};